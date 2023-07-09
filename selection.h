#include "colors.h"

/*======================================================================================
This header file contains the functions that activate the dialougue and call the proper 
color scheme functions based on what the user selects on the menu outlined in main.cpp

For example, if the user selects that they want a complementary color as a part of their 
palette, then the selectComplentary function will execute and ask the user for the needed 
information 
======================================================================================*/

void selectComplementary(){
    int baseHue;
    std::cout << "Enter the base color hue (0-359): ";
    std::cin >> baseHue;

    int complementaryHue;
    complementaryColor(baseHue, complementaryHue);

    std::cout << "Base Color: Hue " << baseHue << std::endl;
    std::cout << "Complementary Color: Hue " << complementaryHue << std::endl;
}

void selectAnalogous(){
    int baseHue;
    std::cout << "Enter the base color hue (0-359): ";
    std::cin >> baseHue;

    int numOfColors;
    std::cout << "Enter the number of analogous colors to generate: ";
    std::cin >> numOfColors;

    int angle;
    std::cout << "Enter the angle between the analogous colors: ";
    std::cin >> angle;

    int* analogousHues = new int[numOfColors];
    analogousColors(baseHue, numOfColors, angle, analogousHues);

    std::cout << "Base Color: Hue " << baseHue << std::endl;
    std::cout << "Analogous Colors:" << std::endl;
    for (int i = 0; i < numOfColors; ++i) {
        std::cout << "Color " << i + 1 << ": Hue " << analogousHues[i] << std::endl;
    }

    delete[] analogousHues;
    
}

void selectTriadic(){
    int baseHue;
    std::cout << "Enter the base color hue (0-359): ";
    std::cin >> baseHue;

    int triadicHues[3];
    triadicColors(baseHue, triadicHues);

    std::cout << "Base Color: Hue " << baseHue << std::endl;
    std::cout << "Triadic Colors:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << "Color " << i + 1 << ": Hue " << triadicHues[i] << std::endl;
    }
}

void selectMonochromatic(){
    int baseHue;
    std::cout << "Enter the base color hue (0-359): ";
    std::cin >> baseHue;

    int numOfColors;
    std::cout << "Enter the number of monochromatic colors to generate: ";
    std::cin >> numOfColors;

    float minSaturation, maxSaturation;
    std::cout << "Enter the minimum and maximum saturation (0-100): ";
    std::cin >> minSaturation >> maxSaturation;

    float minLightness, maxLightness;
    std::cout << "Enter the minimum and maximum lightness (0-100): ";
    std::cin >> minLightness >> maxLightness;

    int* monochromaticHues = new int[numOfColors];
    monochromaticColors(baseHue, numOfColors, minSaturation, maxSaturation, minLightness, maxLightness, monochromaticHues);

    std::cout << "Base Color: Hue " << baseHue << std::endl;
    std::cout << "Monochromatic Colors:" << std::endl;
    for (int i = 0; i < numOfColors; ++i) {
        std::cout << "Color " << i + 1 << ": Hue " << monochromaticHues[i] << std::endl;
    }

    delete[] monochromaticHues;
}

void selectTetradic(){
    int baseHue;

    std::cout << "Enter the base color hue (0-359): ";
    std::cin >> baseHue;

    std::vector<int> tetradicColorVect = tetradicColors(baseHue);

    int counter = 1;

    for(int i: tetradicColorVect){
        std::cout << "Hue #" << counter <<": ";
        std::cout << i << std::endl;
        counter++;
    }

}