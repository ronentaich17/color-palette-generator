#include "selection.h"

//using namespace std;
int main(){

    int choice;

    std::cout << "Welcome to the Color Palette Generator! Please select the color scheme you would like:\n";
    std::cout << "--------------------------------------------------------------------------------------\n";
    std::cout << "0: Quit\n";
    std::cout << "1: Complementary\n";
    std::cout << "2: Analogous\n";
    std::cout << "3: Triadic\n";
    std::cout << "4: Monochromatic\n";
    std::cout << "--------------------------------------------------------------------------------------\n";
    
    


    while(choice != 0){
        std::cout << "Enter: ";
        std::cin >> choice;

        if(choice == 0){
            std::cout << "Thank you for using the color palette generator!\n";
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
            
            default:
                std::cout << "Invalid choice\n";
        
        }
    }
   
    return 0;
}