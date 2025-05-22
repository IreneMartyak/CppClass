#include <iostream>
using namespace std;

class SortBehavior
{
    public:
        virtual void sort() const = 0;
};

class Merge: public SortBehavior
{
    public:
        virtual void sort() const {
            cout << "Merge sort()\n";
        }
};

class Quick: public SortBehavior {
    public:
        virtual void sort() const {
            cout << "Quick sort()\n";
        }
};

class Heap: public SortBehavior
{
    public:
        virtual void sort() const {
            cout << "Heap sort()\n";
        }
};

class SearchBehavior
{
    public:
        virtual void search() const = 0;
};

class Sequential: public SearchBehavior
{
    public:
        virtual void search() const {
            cout << "Sequential search()\n";
        }
};

class BinaryTree: public SearchBehavior
{
    public:
        virtual void search() const {
            cout << "BinaryTree search()\n";
        }
};

class HashTable: public SearchBehavior
{
    public:
        virtual void search() const {
            cout << "HashTable search()\n";
        }
};

// Context
class Collection
{
    private:
        SortBehavior* m_sort;
        SearchBehavior* m_search;
    public:
        Collection(){
            m_search =NULL;
            m_sort = NULL;
        }
        void set_sort(SortBehavior* s){

            m_sort = s;
        }
        void set_search(SearchBehavior* s){
            m_search = s;
        }
        void sort() const {
            if(m_sort)
                m_sort->sort();
        }
        void search() const {
            if(m_search)
                m_search->search();
        }
};


int main(int argc, char *argv[])
{
    Merge merge;
   
    Heap heap;

    Sequential sequential;
    BinaryTree binaryTree;
    HashTable hashTable;

    Collection colA;
    colA.set_sort(&merge);
    colA.sort();

    Collection colB;
    colB.set_search(&binaryTree);
    colB.search();
    { 
        Quick quick;
        colA.set_sort(&quick);
        colA.sort();
        colA.set_sort(nullptr);
    }


    return 0;
}
