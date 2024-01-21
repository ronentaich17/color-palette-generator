#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*======================================================================================
algorithms that produce the colors in the palette based on the scheme that the user selects
on the menu. in-depth descriptions of how each scheme work is available in README.md 
======================================================================================*/

/*function to calculate the complementary color
-----------------------------------------------
modding by 360 degrees ensures that the resulting 
hue value will be within 0-359 degrees
-----------------------------------------------*/

void complementaryColor(int baseHue, int& complementaryHue){
    complementaryHue = (baseHue + 180) % 360;
}

/*function to calculate analogous color
----------------------------------------------
first, the number of analogous colors and the hue 
range is generated. then, offset detmermines the 
difference in hue betweeneach of the analogous colors
----------------------------------------------*/
void analogousColors(int baseHue, int numColors, int angle, int* analogousHues){
    int halfRange = angle/2;

    for(int i = 0; i < numColors; ++i){
        int offset = (i - numColors / 2) * angle / (numColors - 1);
        analogousHues[i] = (baseHue + offset + 360) % 360;
    }
}

/*function to calculate triadic colors
----------------------------------------------
detailed descrpition in README.md
----------------------------------------------*/
void triadicColors(int baseHue, int* triadicHues){
    triadicHues[0] = baseHue;
    triadicHues[1] = (baseHue + 120) % 360;
    triadicHues[2] = (baseHue + 240) % 360;

}

/*function to calculate monochromatic colors
----------------------------------------------
monochromatic color schemes usually use variations of a single hue while
keeping light and saturation constant. the saturation and lightness values here would
range from 0 to 1. the algorithm uses a linear interpolation approach in order to
evenly distribute values between the epscified minimum and maximum ranges
----------------------------------------------*/
void monochromaticColors(int baseHue, int numColors, float minSaturation, float maxSaturation, float minLightness, float maxLightness, int* monochromaticHues){
    float hue = baseHue;
    float satRange = maxSaturation - minSaturation;
    float lightRange = maxLightness - minLightness;

    for(int i = 0; i < numColors; ++i){
        float saturation = minSaturation + (static_cast<float>(i) / (numColors - 1)) * satRange;
        float lightness = minLightness + (static_cast<float>(i) / (numColors - 1)) * lightRange;

        monochromaticHues[i] = static_cast<int>(hue);

        hue = fmod((hue + 30), 360);
    }
}

/*function to calculate tetradic colors
----------------------------------------------
Using the base hue given by the user, the algorithm 
generates the rest of the hues in the color scheme 
by calculating the next hue and adding it to the vector, 
which will return the final hues in the color palette
----------------------------------------------*/

vector<int> tetradicColors(int baseHue){
    vector<int> tetradicColors;
    int spacing = 60; //tetradic colors are spaced 60 degrees apart

    tetradicColors.push_back(baseHue); //first color will be the base hue

    for (int i = 1; i < 4; i++){
        int currHue = (baseHue + (i * spacing)) % 360; 
        tetradicColors.push_back(currHue);
    }

    return tetradicColors;
}