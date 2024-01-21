#include "selection.h"
/*========================================================================================
main menu
=========================================================================================*/

int main(){

    int choice;

    cout << "Welcome to the Color Palette Generator! Please select the color scheme you would like:\n";
    cout << "--------------------------------------------------------------------------------------\n";
    cout << "0: Quit\n";
    cout << "1: Complementary\n";
    cout << "2: Analogous\n";
    cout << "3: Triadic\n";
    cout << "4: Monochromatic\n";
    cout << "5: Tetradic\n";
    cout << "--------------------------------------------------------------------------------------\n";
    
    
    while(choice != 0){
        cout << "Enter Option: ";
        cin >> choice;

        if(choice == 0){
            cout << "Thank you for using the color palette generator!\n";
            break;
        }


        switch(choice){
            case 1:
                selectComplementary();
                break;
            
            case 2:
                selectAnalogous();
                break;
            
            case 3:
                selectTriadic();
                break;
                    
            case 4:
                selectMonochromatic();
                break;
            
            case 5:
                selectTetradic();
                break;
            
            default:
                cout << "Invalid choice\n";
        
        }
    }
   
    return 0;
}