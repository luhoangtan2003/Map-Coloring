#include<bits/stdc++.h>
using namespace std;

vector<string> States = {"WA", "NT", "Q", "NSW", "V", "SA", "T"};
vector<string> Colors = {"Red", "Blue", "Green"};

unordered_map<string, vector<string>> Neighbors;
unordered_map<string, string> Colors_of_States;

void Init_Neighbors() {
    Neighbors["WA"] = {"NT", "SA"};
    Neighbors["V"] = {"SA", "NSW"};
    Neighbors["NT"] = {"WA", "SA", "Q"};
    Neighbors["NSW"] = {"Q", "SA", "V"};
    Neighbors["Q"] = {"NT", "SA", "NSW"};
    Neighbors["SA"] = {"WA", "NT", "Q", "NSW", "V"};
    Neighbors["T"] = {"V"};
}

int Valid_Color(const string& State, const string& Color){
    for (const string& Neighbor : Neighbors[State]){
        if (Colors_of_States[Neighbor] == Color){
            return 0;
        }
    }
    return 1;
}

string Colorize_State(const string& state){
    for (const string& Color : Colors){
        if (Valid_Color(state, Color)){
            return Color;
        }
    }
    return "";
}

int main() {
    Init_Neighbors();
    for (const string& State : States){
        Colors_of_States[State]=Colorize_State(State);
    }
    for (const auto& Entry : Colors_of_States){
        cout<<Entry.first<<" = "<<Entry.second<<endl;
    }
}