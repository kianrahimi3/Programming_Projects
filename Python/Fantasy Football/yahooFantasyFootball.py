from yahoo_oauth import OAuth2
import yahoo_fantasy_api as yfa
import pandas as pd
import numpy as np

#connect to Yahoo API
sc = OAuth2(None, None, from_file='oauth2.json')

# yahoo game class
gm = yfa.Game(sc=sc, code='nfl')

print("game id = ", gm.game_id())

# yahoo league class
lg = yfa.League(sc=sc, league_id=gm.league_ids()[-1])


print("Which option would you like to see?")
print("\t1. League Settings")
print("\t2. League Teams")
print("\t3. League Standings")
print("\t4. Draft Results")
print("\t5. Week Matchups")
print("\t6. Waiver Wire")
choice = input("Choice: ")
print()

try:
    choice = int(choice)
except:
    print("Invalid Choice")


#pull league settings
if choice == 1:
    settings = lg.settings()

    print("\tURL:", settings['url'])
    print("\tLeague Name:", settings['name'])
    print("\tDraft Status:", settings['draft_status'])
    print("\tNo Teams:", settings['num_teams'])
    print("\tLeague Start Date:", settings['start_date'])
    print("\tLeague End Date:", settings['end_date'])
    print("\tTrade End Date:", settings['trade_end_date'])




#pull team names
if choice == 2:
    teams = lg.teams()
    
    
    # yahoo team class
    #tm = yfa.Team(sc=sc, teams[0])
    #print(teams)
    for team in teams:
        print(f"\t{teams[team]['name']}", "-->", teams[team]['managers'][0]['manager']['nickname'])


#pull league standings
if choice == 3:
    standings = lg.standings()

    for team in standings:
        print(f"\tRank {team['rank']}.", team['name'])

#see draft results
if choice == 4:
    draft_res = lg.draft_results()
    teams = lg.teams()

    for i in range(len(draft_res)):
        temp_res = draft_res[i]
        team = teams[temp_res['team_key']]['name']
        print(f"\t{team} - Round",  temp_res['round'], "pick", temp_res['pick'], "-->", lg.player_details(temp_res['player_id'])[0]['name']['full'] )

if choice == 5:
    print("\tCurrent week =", lg.current_week())
    week = input("Choose week: ")
    print()
    matchups = lg.matchups(week)

    fantasy_content = matchups['fantasy_content']
    league_name = fantasy_content['league'][0]['name']

    scoreboard = fantasy_content['league'][1]['scoreboard']
    week = scoreboard['week']
    print(f"\t{league_name}", "Week", week, "matchups:")

    for i in range(int(len(lg.teams()) / 2 )):
        matchups = scoreboard['0']['matchups'][str(i)]['matchup']
        team_1 = matchups['0']['teams']['0']['team']
        team_2 = matchups['0']['teams']['1']['team']
        print(f"\t{team_1[0][2]['name']}", 'VS.', team_2[0][2]['name'])


if choice == 6:

    print("\tSpecific Position?")
    print("\t0. All positions")
    print("\t1. QB")

    position_choice = int(input("Choice: "))

    players_list = []

    print("Fetching Waiver Wire Players")
    waivers = lg.waivers()

    for i in range(len(waivers)):
        temp_list = []
        temp_list.append(waivers[i]['name'])
        temp_list.append(waivers[i]['eligible_positions'])
        temp_list.append(waivers[i]['percent_owned'])

        #points for each player...will change later in program
        temp_list.append(0.0)

        players_list.append(temp_list)

    

    players = pd.DataFrame(players_list)
    players.columns = ["name", "eligible_positions", "percent_owned", "points"]

    players = players.astype({"percent_owned": int, "points": np.float16})
    

    #sort by points
    #players.sort_values('points')
    
    
    print("Done")

    # all positions
    if position_choice == 0:

        players.sort_values('percent_owned')

        for i in range(15):
            players['points'].loc[i] = lg.player_details(players['name'].loc[i])[0]['player_points']['total']

        #for index, row in players.iterrows():
        #    row['points'] = lg.player_details(row['name'])[0]['player_points']['total']

        print(players.head(15))

    
    if position_choice == 1:
        df = players[players['eligible_positions'].str.contains("QB", regex=False)]

        print(df.head())


    # in case if i want to have user continuously run program
    players_list.clear()

print()
    
    


