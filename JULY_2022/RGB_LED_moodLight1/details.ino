/*

When you run this, you will see the colors slowly change. You’ve just made your own mood lamp.

Code  Antonyms Arduino RGB Mood Lamp :

We have used an RGB LED. This is a single 5mm LED, with four legs (some
have more). One leg is either a common anode (positive) or common cathode (negative) and the other three go to the opposite terminal of the red, green, and blue LEDs inside the lamp.

An RGB value of 255, 0, 0 would give us pure red. A value of 0, 255, 0 would give pure green, and 0, 0, 255, pure blue. By mixing these, we can get any color we like. This is the additive color model.

In the code, we start off by declaring some floating point arrays and also some integer variables that will store our RGB values as well as an increment value.
float RGB1[3];
float RGB2[3];
float INC[3];
int red, green, blue;
In the setup function, we have
randomSeed(analogRead(0));

The randomSeed command is used for creating random (actually pseudo-random) numbers. Computer chips are not able to produce truly random numbers, so they use a mathematical function that generates a very long sequence of pseudo-random values before repeating. By setting a “seed,” you can tell the computer wherein the sequence to start returning random numbers. In this case, the value we give to the randomSeed is a value read from analog pin 0.

As we don’t have anything connected to analog pin 0, all we will read is a random number created by analog noise. Once we have set a “seed” for our random number, we can create one using the random() function.
We then have two sets of RGB values stored in a three-element array. RGB1 is the RGB value we want the lamp to start with (in this case, all zeros or off).
RGB1[0] = 0;
RGB1[1] = 0;
RGB1[2] = 0;
The RGB2 array is a set of random RGB values that we want the lamp to transition to

RGB2[0] = random(256);
RGB2[1] = random(256);
RGB2[2] = random(256);
In this case, we have set the RGB values to a random number set by random(256), which will give us a number between 0 and 255 inclusive (as the number will always range from zero upward). If you pass a single number to the random() function, then it will return a value between 0 and 1 less than the number; random(1000) will return a number between 0 and 999.

If you supply two numbers as parameters, then it will return a random number between the lower number inclusive and the maximum number minus 1 (−1). For example, random(10,100) will return a random number between 10 and 99. In the main program loop, we first take a look at the start and end RGB values and work out which value is needed as an increment to progress from one value to the other in 256 steps (as the PWM value can only be between 0 and 255). We do this with
for (int x=0; x<3; x++) {
INC[x] = (RGB1[x] – RGB2[x]) / 256;
}
This for loop sets the INCrement values for the R, G, and B channels by working out the difference
between the two brightness values and dividing that by 256. We then have another for loop
for (int x=0; x<256; x++) {
red = int(RGB1[0]);
green = int(RGB1[1]);
blue = int(RGB1[2]);
analogWrite (RedPin, red);
analogWrite (GreenPin, green);
analogWrite (BluePin, blue);
delay(100);
RGB1[0] -= INC[0];
RGB1[1] -= INC[1];
RGB1[2] -= INC[2];
}
and this sets the red, green, and blue values to the values in the RGB1 array, writes those values to pins 9, 10 and 11, then deducts the increment value, and then repeats this process 256 times to slowly fade from one random color to the next. The delay of 100 ms in between each step ensures a slow and steady progression.

You can, of course, adjust this value if you want it slower or faster, or you can
add a potentiometer to allow the user to set the speed. After we have taken 256 slow steps from one random color to the next, the RGB1 array will have
the same values (nearly) as the RGB2 array. We now need to decide upon another set of three random values ready for the next time. We do this with another for loop
for (int x=0; x<3; x++) {
RGB2[x] = random(556)-300;
RGB2[x] = constrain(RGB2[x], 0, 255);
delay(1000);
}
The random number is chosen by picking a random number between 0 and 556 (256 + 300) and then deducting 300. The reason we do this is to try and force primary colors from time to time to ensure that we don’t always just get pastel shades. We have 300 chances out of 556 of getting a negative number and therefore forcing a bias towards one or more of the other two color channels.

The next command makes sure that the numbers sent to the PWM pins are not negative by using the constrain() function. The constrain function requires three parameters; x, a, and b as in constrain(x, a, b) where x is the number we want to constrain, a is the lower end of the range, and b is the higher end.

So, the constrain function looks at the value of x and makes sure it is within the range of a to b. If it is lower than a, then it sets it to a; if it is higher than b, it sets it to b. In our case, we make sure that the number is between 0 and 255, which is the range of our PWM output. As we use random(556)-300 for our RGB values, some of those values will be lower than zero, and the constrain function makes sure that the value sent to the PWM is not lower than zero.

*/
