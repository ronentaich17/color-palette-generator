# Hue-Based Color Palette Generator

## This program generates hue-based color palettes based off existing color schemes, such as complementary, tetradic, etc.

This collection of C++ algorithms generates hue-based color palettes based on values given by the user. The menu presents user with a variety of color schemes to chose and after selecting their desired option, the user will then enter a base hue, which serves as a reference for the other colors generated by the algorithm.

## Project Layout

`main.cpp` contains the menu that activates when users start the application.

`selection.h` contains the actions that are performed depending on what the user selects on the menu (such as entering base hue and the amount of colors in output palette)

`colors.h` contains the algorithms used to generate the hues in the color palette

Here are the color schemes that the algorithms are based on:

### Complementary

Complementary colors are opposite to the base on the color wheel. This produces two colors that compliment each other contrast-wise. An example of this would be orange and blue. Its hue is found by adding 180 degrees to the base hue. Modding by 360 degrees ensures that the resulting hue value will be within the range of 0-359 degrees

### Analogous

Analogous colors are comprsied of groups of colors that are adjacent to each other on the color wheel. Usually, it is made up of three colors but doesn't
necessarily limited to that. Sometimes, it can go up to four or five colors. An example of this would be green-yellow-orange.

### Triadic

Traidic colors are colors that are evenly spaced on the color wheel.
typically, they are 120 degrees apart, so the values 120 and 240
are used to calculate the two non-base values in the triadicHues array.
An example of such a color scheme would be red-yellow-blue.

### Monochromatic

Monochromatic colors are made up of a singular color. It only uses variations of that colors hue, which is made by altering the brightness and
satruation of that color. An example of something that uses a monochromatic color scheme would be the grayscale.

### Tetradic

Tetradic colors are two sets of complimentary colors that are found on opposite ends of the color wheel. Essentially, they are four colors, each evenly spaced across the wheel at 60 degrees. Using such a technique tends to provide a good balance between warm and cool colors. An example of this would be blue-orange and green-red.

### Future Plans

Future plans for the project include adding more schemes, potentiall generating base hues automatically
(or giving users the option to), and adding a GUI
