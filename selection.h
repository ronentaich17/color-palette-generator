#include "colors.h"

/*======================================================================================
This header file contains the functions that activate the dialougue and call the proper 
color scheme functions based on what the user selects on the menu outlined in main.cpp

For example, if the user selects that they want a complementary color as a part of their 
palette, then the selectComplentary function will execute and ask the user for the needed 
information! 
======================================================================================*/

void selectComplementary(){
    int baseHue;
    cout << "Enter the base color hue (0-359): ";
    cin >> baseHue;

    int complementaryHue;
    complementaryColor(baseHue, complementaryHue);

    cout << "Base Color: Hue " << baseHue << endl;
    cout << "Complementary Color: Hue " << complementaryHue << endl;
}

void selectAnalogous(){
    int baseHue;
    cout << "Enter the base color hue (0-359): ";
    cin >> baseHue;

    int numOfColors;
    cout << "Enter the number of analogous colors to generate: ";
    cin >> numOfColors;

    int angle;
    cout << "Enter the angle between the analogous colors: ";
    cin >> angle;

    int* analogousHues = new int[numOfColors];
    analogousColors(baseHue, numOfColors, angle, analogousHues);

    cout << "Base Color: Hue " << baseHue << endl;
    cout << "Analogous Colors:" << endl;
    for (int i = 0; i < numOfColors; ++i) {
        cout << "Color " << i + 1 << ": Hue " << analogousHues[i] << endl;
    }

    delete[] analogousHues;
    
}

void selectTriadic(){
    int baseHue;
    cout << "Enter the base color hue (0-359): ";
    cin >> baseHue;

    int triadicHues[3];
    triadicColors(baseHue, triadicHues);

    cout << "Base Color: Hue " << baseHue << endl;
    cout << "Triadic Colors:" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "Color " << i + 1 << ": Hue " << triadicHues[i] << endl;
    }
}

void selectMonochromatic(){
    int baseHue;
    cout << "Enter the base color hue (0-359): ";
    cin >> baseHue;

    int numOfColors;
    cout << "Enter the number of monochromatic colors to generate: ";
    cin >> numOfColors;

    float minSaturation, maxSaturation;
    cout << "Enter the minimum and maximum saturation (0-100): ";
    cin >> minSaturation >> maxSaturation;

    float minLightness, maxLightness;
    cout << "Enter the minimum and maximum lightness (0-100): ";
    cin >> minLightness >> maxLightness;

    int* monochromaticHues = new int[numOfColors];
    monochromaticColors(baseHue, numOfColors, minSaturation, maxSaturation, minLightness, maxLightness, monochromaticHues);

    cout << "Base Color: Hue " << baseHue << endl;
    cout << "Monochromatic Colors:" << endl;
    for (int i = 0; i < numOfColors; ++i) {
        cout << "Color " << i + 1 << ": Hue " << monochromaticHues[i] << endl;
    }

    delete[] monochromaticHues;
}

void selectTetradic(){
    int baseHue;

    cout << "Enter the base color hue (0-359): ";
    cin >> baseHue;

    vector<int> tetradicColorVect = tetradicColors(baseHue);

    int counter = 1;

    for(int i: tetradicColorVect){
        cout << "Hue #" << counter <<": ";
        cout << i << endl;
        counter++;
    }

}