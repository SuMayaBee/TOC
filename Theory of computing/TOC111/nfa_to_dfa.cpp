#include<bits/stdc++.h>
using namespace std;

int state_num,sym_num;
char starting_state,final_state;
map<char,int> states_in,symbols_in;
vector<char> states,symbols;
vector<vector<vector<char>>> nfa_transition_table;
set<set<char>> dfa_states,used_states;
vector<vector<int>> dfa_transition_table;

void read_input();
void print_nfa_transition_table();
void convert_to_dfa();
bool is_used(set<char> s);
void print_dfa_states();
int get_index_of_set(set<char> st);
void print_dfa_transition_table();

int main(){
   // freopen("lab4.txt","r",stdin);
    read_input();
    // print_nfa_transition_table();
    convert_to_dfa();
    print_dfa_states();
    print_dfa_transition_table();
    cout<<endl<<"Starting state of the dfa: 0"<<endl<<endl;
    cout<<"Final states: ";
    int i=0;
    for(auto s:dfa_states){
        for(auto e:s){
            if(e==final_state){
                cout<<i<<" ";
                break;
            }
        }
        i++;
    }
    cout<<endl;
    return 0;
}

void read_input(){
    cin>>state_num>>sym_num;
    getchar();
    char ch;
    for(int i=0;i<state_num;i++){
        cin>>ch;
        states.push_back(ch);
        states_in[ch]=i;
        // cout<<states[states_in[ch]]<<" ";
    }
    // cout<<endl;
    getchar();
    for(int i=0;i<sym_num;i++){
        cin>>ch;
        symbols.push_back(ch);
        symbols_in[ch]=i;
        // cout<<symbols[symbols_in[ch]]<<" ";
    }
    // cout<<endl;
    getchar();
    cin>>starting_state>>final_state;
    // cout<<starting_state<<" "<<final_state<<endl;
    nfa_transition_table.resize(state_num,vector<vector<char>>(sym_num,vector<char>(state_num)));
    int transition_num;
    for(int i=0;i<state_num;i++){
        for(int j=0;j<sym_num;j++){
            cin>>transition_num;
            nfa_transition_table[i][j].clear();
            for(int k=0;k<transition_num;k++){
                cin>>ch;
                nfa_transition_table[i][j].push_back(ch);
            }
        }
    }
}

void print_nfa_transition_table(){
    for(auto st:states){
        cout<<"\nFor state-"<<states[states_in[st]]<<":"<<endl;
        for(auto sym:symbols){
            cout<<"For symbol-"<<symbols[symbols_in[sym]]<<": ";
            for(auto e:nfa_transition_table[states_in[st]][symbols_in[sym]]){
                cout<<e<<" ";
            }
            cout<<endl;
        }
    }
}

bool is_used(set<char> s){
    for(auto st:used_states){
        if(s==st){
            return true;
        }
    }
    return false;
}

void convert_to_dfa(){
    dfa_states.insert({starting_state});
    for(int i=0;i<dfa_states.size();i++){
        auto it=next(dfa_states.begin(),i);
        set<char> ds=*it;
        if(is_used(ds)){
            continue;
        }
        for(auto sym:symbols){
            set<char> st;
            for(auto s:ds){
                for(auto e:nfa_transition_table[states_in[s]][symbols_in[sym]]){
                    st.insert(e);
                }
            }
            dfa_states.insert(st);
        }
        used_states.insert(ds);
    }
    dfa_transition_table.resize(dfa_states.size(),vector<int>(sym_num));
    for(auto ds:dfa_states){
        for(auto sym:symbols){
            set<char> st;
            for(auto s:ds){
                for(auto e:nfa_transition_table[states_in[s]][symbols_in[sym]]){
                    st.insert(e);
                }
            }
            dfa_transition_table[get_index_of_set(ds)][symbols_in[sym]]=get_index_of_set(st);
        }
    }
}

void print_dfa_states(){
    int i=0;
    cout<<endl;
    cout<<"States for the DFA:"<<endl;
    for(auto s:dfa_states){
        cout<<i++<<"={";
        for(auto e:s){
            cout<<" "<<e;
        }
        cout<<" }"<<endl;
    }
    cout<<endl;
}

int get_index_of_set(set<char> st){
    int i=0;
    for(auto s:dfa_states){
        if(s==st){
            return i;
        }
        i++;
    }
    return -1;
}

void print_dfa_transition_table(){
    cout<<"Transition table for the DFA:"<<endl;
    cout<<"\t";
    for(auto sym:symbols){
        cout<<"Sym-"<<sym<<"\t";
    }
    cout<<endl;
    int i=0;
    for(auto s:dfa_states){
        cout<<"State-"<<i++<<"\t";
        for(auto sym:symbols){
            cout<<dfa_transition_table[get_index_of_set(s)][symbols_in[sym]]<<"\t";
        }
        cout<<endl;
    }
}