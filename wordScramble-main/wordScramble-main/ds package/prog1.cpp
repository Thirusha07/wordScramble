#include<iostream>
#include<cstring>
#include<fstream>
#include <bits/stdc++.h>
using namespace std;
struct TrieNode
{
    bool isComplete=false;
    TrieNode *children[26]={NULL};
};
class Trie
{
    TrieNode *root=NULL;
    int flag;
public:
    Trie();
    void insertWord(string word);
    bool searchWord(string word);
    void addnewword(string word);
    int permute(string);
    void addWord();
};
Trie::Trie()
{
    root=new TrieNode();
    flag=0;
}
void Trie::insertWord(string word)
{
    TrieNode* currNode=root;
    for(char c:word)
    {
        if(currNode->children[c- 'a']==NULL)
            currNode->children[c-'a']=new TrieNode();
        currNode=currNode->children[c-'a'];
    }
    currNode->isComplete=true;
}
bool Trie::searchWord(string word)
{
    TrieNode* currNode =root;
    for(char c:word )
    {
        if(currNode->children[c-'a']==NULL)
        {
            return false;
            cout<<'1';
        }

        currNode =currNode->children[c-'a'];
    }
    return currNode->isComplete;
}
int Trie::permute(string str)
{
    int flag=0;
   sort(str.begin(), str.end());

   do{
        if(searchWord(str)==1)
        {
            cout<<str<<endl;
            flag=1;
        }

   }while(next_permutation(str.begin(), str.end()));
   return flag;
}
const int MAX = 6;
//generating a string of random alphabets
string gen_random(int n){
   char alphabet[MAX] = {'a','e','t','i','d','n'};
   string res = "";
   for (int i = 0; i < n; i++)
      res = res + alphabet[rand() % MAX];
   return res;
}
void Trie::addWord()
{
     int b;
        string new_word;
        cout<<"Enter the word to add into dictionary:";
        cin>>new_word;
        //ifstream File1("C:\\Users\\thiru\\Downloads\\dict44 (1).txt",ios::in);
        b=searchWord(new_word);
        cout<<b;
        if(b==1)
        {
            cout<<new_word;
            cout<<"This word already exists";
        }
       // if(oTrie.searchWord(new_word)==0)
       else
        {
            ofstream File1("C:\\Users\\Swarneshwar S\\Desktop\\FILES\\SEMESTER 2\\ds package\\dict44 (1).txt",ios::app);
            File1<<new_word<<endl;
            cout<<"The entered new word added successfully"<<endl;
            File1.close();
        }

}
int main()
{
    int choice,length1,n,length2,option=1,a,choice1;
    string  guess;
    while(option!=0)
    {
        cout<<"Enter\n 1.To check a word\n 2.To add a word to dictionary\n 3.To play the game\n 0.Exit:\n";
    cin>>choice;
     string st,word,word1,letters,new_word;
    Trie oTrie;
    if(choice==1)
    {
        ifstream wordfile("C:\\Users\\Swarneshwar S\\Desktop\\FILES\\SEMESTER 2\\ds package\\dict44 (1).txt",ios::in);
        if(!wordfile)
           cout<<"file not opened"<<endl;
        while(!wordfile.eof())
        {
            wordfile>>st;
            word = st;
            oTrie.insertWord(word);
        }
        wordfile.close();
        m:
        cout<<"Enter the letters:";
        cin>>letters;
        length1=letters.length();
        a=oTrie.permute(letters);
        if(a==0)
        {
                cout<<"NO words can be formed with these combinations";
                cout<<"If you want enter another word enter 1:";
                cin>>choice1;
                if(choice1==1)
                   goto m;
        }
    }
    if(choice==2)
    {
        ifstream wordfile("C:\\Users\\Swarneshwar S\\Desktop\\FILES\\SEMESTER 2\\ds package\\dict44 (1).txt",ios::in);
        if(!wordfile)
            cout<<"file  not opened"<<endl;
        while(!wordfile.eof())
        {
            wordfile>>st;
            word = st;
            oTrie.insertWord(word);
        }
        wordfile.close();
        oTrie.addWord();
    }
    if(choice==3)
    {
        ifstream wordfile("C:\\Users\\Swarneshwar S\\Desktop\\FILES\\SEMESTER 2\\ds package\\dict44 (1).txt",ios::in);
        if(!wordfile)
            cout<<"file  not opened"<<endl;
        while(!wordfile.eof())
        {
            wordfile>>st;
            word = st;
            oTrie.insertWord(word);
        }
        wordfile.close();
        srand(time(NULL));
    l:
    cout<<"Enter how many letters:";
    cin>>n;
    cout <<gen_random(n) << endl;
    cout<<"Enter your guess:";
    cin>>guess;
    if(oTrie.searchWord(guess)==1)
        {
            cout<<"Congrats!!!your guess is correct"<<endl;
        }
    else if(oTrie.searchWord(guess)==0)
        {
            // if(oTrie.permute(guess,0,length2))
            {
                  cout<<"NO words can be formed with these combinations"<<endl;
                  goto l;
            }
          //  else
            cout<<"Oops!!!Better luck next time";
            length2=guess.length();

        }
    }
    cout<<"If you want to exit enter 0:";
    cin>>option;
    }
    return 0;
}
