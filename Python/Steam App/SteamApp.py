from steam import Steam
from decouple import config
import numpy as np
import pandas as pd
import sys

def getUserInfo(ID):
    owned_games = steam.users.get_owned_games(ID)

    games = pd.DataFrame()
    games = pd.DataFrame.from_dict(owned_games['games'], orient='columns')

    achievement_counts = []

    for i in owned_games['games']:
        app_id = i['appid']
        #print(i['name'], i['appid'])
        try:
            achievements = steam.apps.get_user_achievements(ID, app_id)
            
            
            if "achievements" in achievements['playerstats']:
                achievements_per_game = achievements['playerstats']["achievements"]

                count = 0
                for j in achievements_per_game:
                    count += j['achieved']
        
        except:
            count = 0
            #print(i['name'], 'could not be calculated')

        achievement_counts.append(count)
        #print(count)


    games['No_Achievements_Earned'] = achievement_counts
    games['playtime_forever_hours'] = (games['playtime_forever'] / 60).round(2)

    return games

def mostPlayedGames(ID):
    df = getUserInfo(ID)
    df = df.sort_values('playtime_forever', ascending=False)
    return df

def mostAchievements(ID):
    df = getUserInfo(ID)
    df = df.sort_values('No_Achievements_Earned', ascending=False)
    return df


def gameSearch(term):
    search = steam.apps.search_games(term)
    results = pd.DataFrame.from_dict(search['apps'], orient='columns')
    results.drop(['id', 'img', 'link'], axis=1, inplace=True)

    return results








KEY = config("STEAM_API_KEY")
ID = config("STEAM_API_ID")

steam = Steam(KEY)

# arguments: steamid
user = steam.users.get_user_details('76561198849498780')


while True:
    print("Select which choice you would like to see:")
    print("\t1. Top 10 most played games")
    print("\t2. Top 10 games with most achievements")
    print("\t3. Search a game")

    print("\t-1. Exit")

    user_input = input("Input: ")


    if user_input == '-1':
        sys.exit()

    if user_input == '1':
        df = mostPlayedGames(ID)
        df = df[['name', 'playtime_forever_hours', 'No_Achievements_Earned']].head(10)
        print(df.head(10))
        print()

    if user_input == '2':
        df = mostAchievements(ID)
        df = df[['name', 'playtime_forever_hours', 'No_Achievements_Earned']].head(10)
        print(df.head(10))
        print()

    if user_input == '3':
        try:
            term = input("Search Term:")
        except:
            term = ""
        results = gameSearch(term)
        print(results.head(10))
        print()


