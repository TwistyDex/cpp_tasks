#include <iostream>
#include <map>
#include <string>
#include <numeric>
#include<iomanip>

using namespace std;



int n, n1;
string s1;

multimap<string, int> mappy;
multimap<string, int> output;

void getinput()
{
    cout << "How many pairs do you want to store :";
    cin >> n;
    cout << "#### Enter the pair ####" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the pair_" << i + 1 << endl;
        cout << "Key :";
        cin >> s1;
        cout << "Value :";
        cin >> n1;
        mappy.insert(multimap<string, int>::value_type(s1, n1));
        cout << endl;
    }
}

void display()
{
    cout << "#### The data stored ####\n";
    cout << setw(4)<<"Key : Value\n";
    for (auto mappy1 : mappy)
    {
      cout << setw(4)<<mappy1.first << ":" << mappy1.second << endl;
    }
    auto mp =mappy.begin();
    output.insert(multimap<string,int>::value_type(mp->first ,mp->second));
}

void check()
{

for(auto ch =next(mappy.begin());ch!=mappy.end();++ch)
{
    int x =1;
    for(auto fx:output)
    {


        if(ch->first ==fx.first)
        {

            ch->second=ch->second+fx.second;
            output.erase(ch->first);
            output.insert(multimap<string,int>::value_type(ch->first ,ch->second));
            break;
        }
        else
        {
            if(x == output.size())
            {
                  output.insert(multimap<string,int>::value_type(ch->first ,ch->second));
                  break;
            }
        }
        x++;
    }
cout << endl;
}
}
void last()
{
    cout << "#### The final output####\n";
    cout << setw(4)<<"Key : Value\n";

    for (auto sh : output)
    {
      cout <<setw(4)<<sh.first << " : " << sh.second << endl;
    }
}

int main()
{
   getinput();
   display();
   check();
   last();
   return 0;
}
