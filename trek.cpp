#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdio>
using namespace std;

vector<float> baseKsanteStats_lvl(float lvl){
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
	vector<float> v= {hp,mana,dmg,armr,mr,totalhaste,total_as,total_ms};
	return v;
}	


vector<float>spells_stats_e(int points,float bonus_hp,float haste){
	float mult=1.15;
	float t_cd=(haste/(100+haste));
	vector<float> sheild_str={mult*bonus_hp*80,mult*bonus_hp*120,mult*bonus_hp*160,mult*bonus_hp*200,mult*bonus_hp*240};
	vector<float> cd1={10,9.5,9,8.5,8};
	vector<float> cd;
	for (float cdr:cd1){
		cd.push_back(t_cd*cdr);
	}
	int ind=points-1;
	vector <float> v;
	v.push_back(sheild_str[ind]);
	v.push_back(cd[ind]);
	return v;
	
	
}

vector<float> spells_stat_q(int points,float bonus_armor,float bonus_mr,float haste){
	float mincd=3.5;
	float mindcdc=0.1;
	float everyeight=8.0;
	float mult=0.4;
	
	float bonus_r=(bonus_mr+bonus_armor);
	float dmg=mult*bonus_r;
	
	
	for (int i=0;i<15;i++){
		if (bonus_r<8.0){
			break;
		}
		bonus_r=bonus_r-everyeight;
		mincd=mincd-mindcdc;

	}
	vector<float> base_dmg={80.0,110.0,140.0,170.0,200.0};
	vector<float> v;
	v.push_back(base_dmg[points-1]+dmg);
	v.push_back(mincd-(mincd*(haste/(haste+100.0))));
	return	 v;
}

vector<float> spells_stats_w(int points,float op_hp,float bonus_armor,float bonus_mr,float haste){
	vector<float> basecd={24,22,20,18,16};
	vector<float> basedmg={40, 60, 80, 100, 120};
	float cd_m=(haste/(haste+100.0));
	vector<float>fcd;
	for (float kcd:basecd){
		fcd.push_back(kcd-(cd_m*kcd));
	}
	vector<float> v;
	float ind=points-1;
	float min_mult=0.08;
	float every_h=100.0;
	float every_hm=0.02;
	float ba=(bonus_armor/every_h);
	float bm=(bonus_mr/every_h);
	float t_mult=min_mult+((ba+bm)*every_hm);
	float tdmg=basedmg[points-1]+(t_mult*op_hp);
	v.push_back(tdmg);
	v.push_back(fcd[ind]);
	return v;
}

int main(){
	float inputlvl;
	cout<<endl;
	cout<<"To get Ksante Base stats by lvl enter his lvl :"<<endl;
	cin>>inputlvl;
	cout<<"At lvl :"<<inputlvl<<" his stats are as follows : \n\n";
	vector<string> char_staTs={"hp","mana","dmg","armr","mr","ability haste","total_as","total_ms"};
	vector<float> ksante_staTs=baseKsanteStats_lvl(inputlvl);
	cout<<endl;
	int i=0;
	for(string n : char_staTs){
		cout<<"Char "<<n<<" is :"<<printf("%0.2f",ksante_staTs[i])<<endl;
		
		i=i+1;
	}
	
	cout<<endl;
    //points,bonus armor,mr,spellhaste output: dmg and cd .5 sec stun or regular 80% ms_red for 0.5s
	//vector<float>ans=spells_stat_q(5,150.0,12.0,22.0);
	// cout<<"Q dmg :"<<ans[0]<<endl;
	// cout<<"Q cd :"<<ans[1]<<endl;
	
	
	//point,opponent_hp, bonus_armor,bonus_mr,ap haste
	vector<float> ans=spells_stats_w(5,1800.0,150.0,12.0,22.0);
	cout<<"W dmg :"<<ans[0]<<endl;
	cout<<"W cd :"<<ans[1]<<endl;
	//ksanteStats_lvl(13.0)=hp,mana,dmg,armr,mr,ap,total_as;
	//print_staTs(ksante_staTs[0],ksante_staTs[1],ksante_staTs[2],ksante_staTs[3],ksante_staTs[4],ksante_staTs[5],ksante_staTs[6]);
	
	
	return 0;
}

// static void print_staTs(float hp,float mana,float dmg,float armr,float mr,float ap,float total_as ){
// cout<<endl;
// cout<<"health :"<<printf("%.2f",hp)<<endl;
// cout<<"armr :"<<printf("%.2f",armr)<<endl;
// cout<<"mr :"<<printf("%.2f",mr)<<endl;
// cout<<"dmg :"<<printf("%.2f",dmg)<<endl;
// cout<<"attackspeed :"<<printf("%1.2f",total_as)<<endl;
// cout<<endl;


// }


// class Meds{
// 	public:
// 		vector<string> brandNames;
// 		string compoundName;
// 		float stripCountInBox;
// 		float unitsInStrip;
// 		float myReserve;
// 		float unitPrice;
// 		float stripPrice=unitsInStrip*unitPrice;
//
// };

// }
// struct character{
// 	string name;
// 	int level;
// 	float lvl;
// 	float hp=120.0*(lvl-1.0);
// 	// Character(hp);
// 	float mana=60.0*(lvl-1.0);
// 	// Character(mana);endl;
// 	float dmg=64.0+(3.5*(lvl-1.0));
// 	// Character(dmg);
// 	float armr=36.0+(5.2*(lvl-1.0));
// 	// Character(armr);
// 	float mr=30.0+(2.1*(lvl-1.0));
// 	// Character(mr);
// 	float ap=0.0;
// 	// Character(ap);
// 	float bonus_as=pow(1.025,(lvl-1.0));
// 	float base_as=0.625;
// 	float total_as=base_as+bonus_as;
// 	// Character(as);
// };
	

// int main();{
// character k1;
// k1.name="Ksante";
// k1.lvl=14.0;
// cout<<endl;
// cout<<printf("%.2f",k1.lvl)<<endl;
// cout<<"Champ :"<<k1.name<<endl;
// cout<<"health :"<<printf("%.2f",k1.hp)<<endl;
// cout<<"armr :"<<printf("%.2f",k1.armr)<<endl;
// cout<<"mr :"<<printf("%.2f",k1.mr)<<endl;
// cout<<"dmg :"<<printf("%.2f",k1.dmg)<<endl;
// cout<<"attackspeed :"<<printf("%1.2f",k1.base_as)<<endl;
// cout<<endl;

// return 0;
// }	
