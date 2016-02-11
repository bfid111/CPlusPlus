
/*
BMPmodSOURCE.cpp
A BMP file starts with a header that contain various info at specified positions
based on the number of bytes, because it is a binary file.
using the fstream functions, the program will read in a bitmap file, this
must be in 24-bit truecolor in order to work. The end result of the program is
to convert a regular image into it's negative. It can also change a negative
into the positive proof converting the RGB values.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
using namespace std;
void process(int&, int&, int&);
void process1(int&, int&, int&);
void process2(int&, int&, int&);
int getInt(fstream&, int);
int main()
{
	int fileSize;
	int start;
	int width, height;
	int scanLineSize;
	int padding;
	int pos;
	int blue, green, red, white, black;
	cout << "Please enter the file name: ";
	string fileName;
	cin >> fileName;
	fstream stream;
	//open as a binary file
	stream.open(fileName.c_str(), ios::in | ios::out | ios::binary);
	if (stream.fail())
	{
		cout << "File not found." << endl;
		system("pause");
		return 1;
	}
	int choice;
	cout << " Input 1  for Sunset Filter " << endl;
	cout << " Input 2 for Grayscale Filter " << endl;
	cout << " Input 3 for Violet Filter " << endl;
	cout << " Choice : ";
	cin >> choice;


	switch (choice)
	{
	case 1:
		fileSize = getInt(stream, 2);
		start = getInt(stream, 10);
		width = getInt(stream, 18);
		height = getInt(stream, 22);
		//scan lines must occupy multiples of four bytes
		scanLineSize = width * 3;
		padding = 0;
		if (scanLineSize % 4 != 0)
		{
			padding = 4 - scanLineSize % 4;
		}
		if (fileSize != start + (scanLineSize + padding) * height)
		{
			cout << "Not a 24-bit true color image file." << endl;
			system("pause");
			return 1;
		}
		pos = start;//go to the start of the pixels
		for (int i = 0; i < height; i++) //for each scan line
		{
			for (int k = 0; k < width; k++) //for each pixel
			{
				stream.seekg(pos);
				red = stream.get();//read the pixel
				green = stream.get();
				blue = stream.get();
				process(blue, green, red);
				stream.seekp(pos); //go back to the start of the pixel
				stream.put(red); //write out the new pixel
				stream.put(green);
				stream.put(blue);
				pos = pos + 3;
			}
			stream.seekg(padding, ios::cur); //skip the padding
		}
		cout << "Done! " << endl;
		break;

	case 2:
		fileSize = getInt(stream, 2);
		start = getInt(stream, 10);
		width = getInt(stream, 18);
		height = getInt(stream, 22);
		//scan lines must occupy multiples of four bytes
		scanLineSize = width * 3;
		padding = 0;
		if (scanLineSize % 4 != 0)
		{
			padding = 4 - scanLineSize % 4;
		}
		if (fileSize != start + (scanLineSize + padding) * height)
		{
			cout << "Not a 24-bit true color image file." << endl;
			system("pause");
			return 1;
		}
		pos = start;//go to the start of the pixels
		for (int i = 0; i < height; i++) //for each scan line
		{
			for (int k = 0; k < width; k++) //for each pixel
			{
				stream.seekg(pos);
				red = stream.get();//read the pixel
				green = stream.get();
				blue = stream.get();
				process1(blue, green, red);
				stream.seekp(pos); //go back to the start of the pixel
				stream.put(red); //write out the new pixel
				stream.put(green);
				stream.put(blue);
				pos = pos + 3;
			}
			stream.seekg(padding, ios::cur); //skip the padding
		}
		cout << "Done! " << endl;
		break;

	case 3:
		fileSize = getInt(stream, 2);
		start = getInt(stream, 10);
		width = getInt(stream, 18);
		height = getInt(stream, 22);
		//scan lines must occupy multiples of four bytes
		scanLineSize = width * 3;
		padding = 0;
		if (scanLineSize % 4 != 0)
		{
			padding = 4 - scanLineSize % 4;
		}
		if (fileSize != start + (scanLineSize + padding) * height)
		{
			cout << "Not a 24-bit true color image file." << endl;
			system("pause");
			return 1;
		}
		pos = start;//go to the start of the pixels
		for (int i = 0; i < height; i++) //for each scan line
		{
			for (int k = 0; k < width; k++) //for each pixel
			{
				stream.seekg(pos);
				red = stream.get();//read the pixel
				green = stream.get();
				blue = stream.get();
				process2(blue, green, red);
				stream.seekp(pos); //go back to the start of the pixel
				stream.put(red); //write out the new pixel
				stream.put(green);
				stream.put(blue);
				pos = pos + 3;
			}
			stream.seekg(padding, ios::cur); //skip the padding
		}
		cout << "Done! " << endl;
		break;
	default:
		system("pause");
		return EXIT_SUCCESS;
		break;

	}


	cout << endl;
	system("pause");
	return EXIT_SUCCESS;
}
/**
Processes a pixel by forming the negative.
@param blue the blue value of the pixel
@param green the green value of the pixel
@param red the red value of the pixel
*/
void process(int& red, int& green, int& blue)
{
	blue = blue - (blue*0.3);
	green = green - (green*0.3);
	red = red;
}
void process1(int& red, int& green, int& blue)
{
	blue = blue - 100;
	green = green - 100;
	red = red - 100;

}
void process2(int& red, int& green, int& blue)
{

	blue = blue - 204;
	green = green - 100;
	red = red - 204;

}
/**
Gets an integer from a binary stream
@param stream the stream
@param offset the offest at which to read the integer
@return the integer starting at the given offset
*/
int getInt(fstream& stream, int offset)
{
	stream.seekg(offset);
	int result = 0;
	int base = 1;
	for (int i = 0; i < 4; i++)
	{
		result = result + stream.get() * base;
		base = base * 256;
	}
	return result;
}