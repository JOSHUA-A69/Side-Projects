#include <stdio.h>
#include <stdlib.h>

int main(){
	// Declare variables for height, weight, and BMI
	float height, weight, bmi;

	// Print a message asking the user for their height in meters
	printf("Enter your height in meters: ");

	// Read the user's height from the standard input
	scanf("%f", &height);

	// Print a message asking the user for their weight in kilograms
	printf("Enter your weight in kilograms: ");

	// Read the user's weight from the standard input
	scanf("%f", &weight);

	// Calculate the BMI by dividing the weight by the square of the height
	bmi = weight / (height * height);

	// Print the BMI to the user
	printf("Your BMI is %.1f\n", bmi);

	// Use a while loop to keep asking the user for their height and weight until they enter 0 for both
	while (height != 0 || weight != 0)
	{
		// Print a message asking the user for their height in meters
		printf("Enter your height in meters (enter 0 to exit): ");

		// Read the user's height from the standard input
		scanf("%f", &height);

		// Print a message asking the user for their weight in kilograms
		printf("Enter your weight in kilograms (enter 0 to exit): ");

		// Read the user's weight from the standard input
		scanf("%f", &weight);

		// If the user has entered 0 for both height and weight, exit the loop
		if (height == 0 && weight == 0)
		{
			break;
		}

		// Calculate the BMI by dividing the weight by the square of the height
		bmi = weight / (height * height);

		// Use an if-else statement to classify the BMI as underweight, normal weight, overweight, or obese
		if (bmi < 18.5)
		{
			printf("Your BMI is %.1f, which is classified as underweight.\n", bmi);
		}
		else if (bmi >= 18.5 && bmi < 25)
		{
			printf("Your BMI is %.1f, which is classified as normal weight.\n", bmi);
		}
		else if (bmi >= 25 && bmi < 30)
		{
			printf("Your BMI is %.1f, which is classified as overweight.\n", bmi);
		}
		else
		{
			printf("Your BMI is %.1f, which is classified as obese.\n", bmi);
		}
	}

	return 0;
}

