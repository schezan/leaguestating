#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
using namespace std;

vector<string> kk;
class baseStats {
public:
string retP;    
int lvl;
    vector <float> baseS;
    // Function to add two integers
    void setBaseStats() {
        cout <<"\n\nEnter lvl to Get Ksante Base Stats :\n\n";
        cin>>lvl;
        cout<<endl;
        float lvl2=lvl;
        baseS=getbaseStats(lvl2);
        
        pBStat(baseS);
    }

    
    // Function to add two floating point values
    vector<float> getbaseStats(float lvl) {
        float hp=625.0+120.0*(lvl-1.0);
        float mana=320.0+60.0*(lvl-1.0);
        float dmg=64.0+(3.5*(lvl-1.0));
        float basehaste=0.0;
        float bonushaste=0.0;
        float totalhaste=basehaste+bonushaste;
            // Character(dmg);
        float armr=36.0+(5.2*(lvl-1.0));
        // Character(armr)
        float mr=30.0+(2.1*(lvl-1.0));
        // Character(mr);
        float ap=0.0;

        // Character(ap);
        float bonus_as=pow(1.025,(lvl-1.0));
        float base_as=0.625;
        float total_as=base_as*bonus_as;
        float bonus_ms=0;
        float base_ms=330.0;
        float total_ms=base_ms+bonus_ms;
        vector<float> v={hp,armr,mr,totalhaste,mana,total_as,total_ms};    
        return v;
    }
    void pBStat(vector<float>baseS1){
       string r;
       int slot=0;
       vector <string> pB={"Base Health","Base Armor","Base Mr","Base Ability Haste","Base Mana","Base AttackSpd","Base MoveSpeed"};
       for(string staname:pB){
       char buffer[4000];
       sprintf(buffer,"%14.28s : %.2f",staname.c_str(),baseS[slot]);
       retP+=buffer;
       slot=slot+1; 
       } 
       
    };
    

};


class bonusStats{
    
    public:
    
    vector<float> bnusSt;
    float bhp,ba,bmr,bhaste;
    string retP1;
    void setBonusStats(){
        cout<<"\n\nSet Bonus Stats : HP,Armor,MR,Haste\n\n";
        cin>>bhp;
        
        cin>>ba;
        cin>>bmr;
        cin>>bhaste;
        bnusSt={bhp, ba, bmr, bhaste};
        bonushp();
        

    };   
     
    
        
    
    // vector<float> getBonusStats(){
    //     vector<float> v={bhp,ba,bmr,bhaste};
    //     return v;
    // }
    void bonushp(){
        vector<string> bnames={"Bonus Hp","Bonus Armor","Bonus Mr","Bonus abilityHaste"};
        int c=0;
        string c1;
        for (string n:bnames){
            char buffer[4000];
            sprintf(buffer,"%40.32s : %0.2f",n.c_str(),bnusSt[c]);
            retP1+=buffer;
            //kk.push_back(buffer);
            c=c+1;
        }
        //return c1;
        
    }

};


