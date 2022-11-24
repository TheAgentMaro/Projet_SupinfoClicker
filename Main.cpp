#include <iostream>
#include "Supinfo Autoclicker.cpp"

using namespace std;

int main(){
    cout<<"==========================HOTKEYS========================="<<endl;
    cout<<"| NUM1-------------Demarrer l'enregistrement des clics---|"<<endl;
    cout<<"| NUM2-------------Arreter l'enregistrement des clics ---|"<<endl;
    cout<<"| NUM3-------------Afficher les clics enregistres--------|"<<endl;
    cout<<"| NUM4-------------Commencer a simuler des clics---------|"<<endl;
    cout<<"| NUM5-------------Quitter le clicker automatique--------|"<<endl;
    cout<<"| NUM6-----------------Menu des touches------------------|"<<endl;
    cout<<"=========================================================="<<endl;
    do{
        if(keypressed(VK_NUMPAD6)){
            cout<<"==========================HOTKEYS========================="<<endl;
            cout<<"| NUM1-------------Demarrer l'enregistrement des clics---|"<<endl;
            cout<<"| NUM2-------------Arreter l'enregistrement des clics ---|"<<endl;
            cout<<"| NUM3-------------Afficher les clics enregistres--------|"<<endl;
            cout<<"| NUM4-------------Commencer a simuler des clics---------|"<<endl;
            cout<<"| NUM5-------------Quitter le clicker automatique--------|"<<endl;
            cout<<"| NUM6-----------------Menu des touches------------------|"<<endl;
            cout<<"=========================================================="<<endl;
        }
        if(keypressed(VK_NUMPAD1)){
            cout<<"|---------la position du curseur est en cours d'enregistrement--------------|"<<endl;
            cout<<"Appuyez sur NUM1 pour enregistrer un clic et appuyez sur NUM2 pour terminer."<<endl;
            cout<<"\n"<<endl;
            CursorPosi();
        }
        if(keypressed(VK_NUMPAD3)){
            for(int j=0;j<click.indexv;++j){               
                cout<<"Cordonnees du clic gauche :"<<lxinput[j]<<","<<lyinput[j]<<endl;
                cout<<"Clic droit sur les coordonnees :"<<rxinput[j]<<","<<ryinput[j]<<endl;
            }
            cout<<"Appuyez sur NUM1 pour enregistrer a nouveau ou sur NUM4 pour simuler les clics enregistres."<<endl;
        }
        if(keypressed(VK_NUMPAD4)){
                //cout<<"press NUM4 to start simulating recorded clicks"<<endl;
                cout<<"Entrez l'intervalle entre deux clics consecutifs en secondes :"<<endl;
                cin>>click.time;
                click.time = click.time*1000;
                while(TRUE){
                    if (!click.conditionII){
					break;
				    }
                    ClickCursor(lxinput,lyinput,rxinput,ryinput,click.time);
                    if(keypressed(VK_NUMPAD5)){
                        system("cls");
					    click.conditionII = false;
					    cout << "|-------------- Arret des clics --------------| " << endl;
				}           
            }
        }
        if(keypressed(VK_NUMPAD5)){
            cout<<"EXITED";
        }
    }while(!keypressed(VK_NUMPAD5));
    return 0;    
}