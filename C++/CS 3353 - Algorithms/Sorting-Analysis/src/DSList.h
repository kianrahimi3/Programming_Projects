//
// Created by kianr on 10/12/2021.
//

#ifndef INC_21F_PA02_KIAN_S_TEAM_DSLIST_H
#define INC_21F_PA02_KIAN_S_TEAM_DSLIST_H


//because using templates, putting everything in .h file

//create DSNodes first
template <typename T>
struct DSNode {
public:
    T data;
    DSNode *next;
    DSNode *prev;

    //used for coordinate
    //T x;
    //T y;

    DSNode() {
        next = nullptr;
        prev = nullptr;
    }
    DSNode(T newData) {
        this->data = newData;
    }

    ~DSNode() {

    };

    DSNode(DSNode<T> &copyNode) {
        data = copyNode.data;
        next = copyNode.next;
        prev = copyNode.prev;
    }

    //same as copy constructor
    DSNode &operator=(const DSNode<T> &copyNode) {
        data = copyNode.data;
        next = copyNode.next;
        prev = copyNode.prev;

        return *this;
    }
};

template <typename T>
class DSList {
private:
    DSNode<T>* head;
    DSNode<T>* tail;
    int size;
public:
    DSList() {
        head = nullptr;
        tail = nullptr;
        size = 0;
    };
    ~DSList() {

    };
    DSList(const DSList<T>& copyList) {

        DSNode<T>* copyTemp = copyList.head;
        for(int i = 0; i < copyList.size; i++) {
            push_back(copyTemp->data);
            copyTemp = copyTemp->next;
        }
        // delete copyTemp;

    };

    DSList &operator=(const DSList &copy) {
        if (this != &copy) {
            if(this->head != nullptr){
                DSNode<T> *temp = head;
                DSNode<T> *tempNext = temp ->next;
                for (int i = 0; i < size; i++) {
                    delete temp;
                    temp = tempNext;
                    if(temp != nullptr){
                        tempNext = temp->next;
                    }
                }
            }

            this->head = nullptr;
            this->tail = nullptr;
            this->size = 0;

            DSNode<T>* temp = copy.head;
            for(int i = 0; i < copy.size; i++){
                push_back(temp->data);
                temp = temp->next;
            }
            //delete temp;
        }

        return *this;
    }

    void push_back(T newData) {

        //if head == empty
        //head and tail == new node
        if(head == nullptr) {
            head = new DSNode<T>(newData);
            tail = head;
            size++;
        }

            // else node after tail = new node
            // set tail.next as tail
        else {
            tail->next = new DSNode<T>(newData);
            tail->next->prev = tail;
            tail = tail->next;
            size++;
        }
    };

    void pop() {
        if(size == 0) {
            //nothing
        }
        else if(size == 1) {
            head = nullptr;
            tail = nullptr;
            size--;
        }
        else {
            tail = tail->prev;
            size--;
        }
    };

    int getSize() {
        return size;
    };

    //this and [] operator are same
    T& at(int index) const {
        DSNode<T>* returnIndex = this->head;
        for(int i = 0; i < index; i++)
            returnIndex = returnIndex->next;

        return returnIndex->data;
    };
    T& operator[](int index) {
        DSNode<T>* returnIndex = this->head;
        for(int i = 0; i < index; i++)
            returnIndex = returnIndex->next;

        return returnIndex->data;
    };


    class iterator {
    private:
        DSNode<T>* node;
    public:
        explicit iterator() : node(nullptr) {};
        explicit iterator(DSNode<T>* temp) : node(temp) {};
        DSNode<T>* Node() const {
            return node;
        };
        T& Value() const {
            return node->data;
        };
        bool Valid() const {
            return (node != nullptr);
        };
        iterator& operator++() {
            if(node->next != nullptr) {
                node = node->next;
            }
            return *this;
        };
        iterator& operator++(int) {
            iterator temp = *this;
            ++(*this);
            return temp;
        };
        iterator& operator--() {
            if(node->prev != nullptr) {
                node = node->prev;
            }
            return *this;
        };
        iterator& operator--(int) {
            iterator temp = *this;
            --(*this);
            return temp;
        };
        bool operator==(const iterator& temp) const {
            return temp.node == this->node;
        };
        bool operator!=(const iterator& temp) const {
            return temp.node != this->node;
        };


    };

    iterator begin() const {
        return iterator(head);
    }
    iterator end() const {
        return iterator(tail);
    }




};




#endif //INC_21F_PA02_KIAN_S_TEAM_DSLIST_H
