#include<iostream>
#include<string>
using namespace std;

struct Trie
{
    bool Finish;
    Trie* Node[11];
    void insert(char* str);
    bool call(char* str);
};

int k, N_Idx;
char Phone[10010][11];
string Answer;
Trie* Root, Nodepool[110110];

Trie* Nodeset()
{
    Trie* NewNode = &Nodepool[N_Idx++];
    NewNode->Finish = false;
    for (int i = 0; i < 11; i++) NewNode->Node[i] = NULL;
    return NewNode;
}

void Trie::insert(char* Str)
{
    if (*Str == NULL)
    {
        Finish = true;
        return;
    }

    int Cur = *Str - '0';
    if (Node[Cur] == NULL) Node[Cur] = Nodeset();
    Node[Cur]->insert(Str + 1);
}

bool Trie::call(char* Str)
{
    if (*Str == NULL) return true;
    if (Finish == true) return false;

    int Cur = *Str - '0';
    return Node[Cur]->call(Str + 1);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int n;
    cin >> n;
    while (n--) {
        N_Idx = 0;
        Root = Nodeset();
        cin >> k;
        for (int i = 0; i < k; i++) 
            cin >> Phone[i];
        for (int i = 0; i < k; i++) Root->insert(Phone[i]);
        bool Flag = true;
        for (int i = 0; i < k; i++)
        {
            if (Flag == true) Flag = Root->call(Phone[i]);
            if (Flag == false) break;
        }
        if (Flag == true) Answer = "YES";
        else Answer = "NO";
        cout << Answer << endl;
    }
    return 0;
}
