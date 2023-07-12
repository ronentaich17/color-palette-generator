#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

/*======================================================================================
This header file contains the algorithms that produce the colors in the palette based on
the scheme that the user selects on the menu shown in main.cpp. For now, they are calculated
off of the base hue, provided by the user
======================================================================================*/

/*function to calculate the complementary color
-----------------------------------------------
the complementary color is the color that opposite to the base 
color on the color wheel. in terms of hue, the complementary 
color is found by adding 180 degrees to the base hue. modding by 
360 degrees ensures that the resulting hue value will be within
the range of 0-359 degrees
-----------------------------------------------*/

void complementaryColor(int baseHue, int& complementaryHue){
    complementaryHue = (baseHue + 180) % 360;
}

/*function to calculate analogous color
----------------------------------------------
the analogous color scheme generates a set of colors that are adjacent
to each other on the color wheel. first, the number of analogous colors and
the hue range is generated. then offset detmermines the difference in hue between
each of the analogous colors
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
traidic colors are colors that are evenly spaced on the color wheel.
typically, they are 120 degrees apart, hence why the values 120 and 240
are used to calculate the two values in the triadicHues array (the first
color is the base hue given by the user)
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
tetradic color schemes are sets of 4 colors, each spaced evenly across the 
color wheel at 60 degrees. using the base hue given by the user, the algorithm 
generates the rest of the hues in the color scheme by calculating the next hue and
adding it to the vector, which will return the final hues in the color palette
----------------------------------------------*/

//thinking of changes all the algorithms to return a data structure instead of being void
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