/*
 * Ex_8_6.h
 *
 *  Created on: Sep 21, 2012
 *      Author: MiTKooK
 */

/*
 * Implement the "paint fill" function that one might see on many image editing programs.
 * That is, given a screen (represented by a 2 dimensional array of Colors), a point, and
 * a new color, fill in the surrounding area until you hit a border of that color.
 */

#include<iostream>
#include<cstdlib>
using namespace std;

enum Colors {
	Black, Red, White
};

void paintAt(Colors ** img, int N, int i, int j, Colors original_color, Colors select_color) {

	if (i < 0 || i >= N || j < 0 || j >= N) // given point is out of image
		return;

	if (img[i][j] == original_color) {
		img[i][j] = select_color;
		paintAt(img, N, i - 1, j, original_color, select_color); // top
		paintAt(img, N, i + 1, j, original_color, select_color); // bottom
		paintAt(img, N, i, j - 1, original_color, select_color); // left
		paintAt(img, N, i, j + 1, original_color, select_color); // right
	}
}

void paintAt(Colors ** img, int N, int i, int j, Colors color) {
	paintAt(img, N, i, j, img[i][j], color);
}

void printImg(Colors ** img, int N) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			switch (img[i][j]) {
			case Black:
				cout << "B";
				break;
			case Red:
				cout << "R";
				break;
			case White:
				cout << "W";
				break;
			default:
				cout << "@";
				break;
			}
		}
		cout << endl;
	}
}

int main() {
	int N = 10;
	Colors **img = new Colors*[N];
	img[0] = new Colors[N * N];
	for (int i = 1; i < N; i++)
		img[i] = img[i - 1] + N;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			img[i][j] = Black;
		}
	}

	for (int i = 0; i < 100; i++) {
		img[rand() % N][rand() % N] = Red;
	}

	printImg(img, N);
	paintAt(img, N, 5, 5, White);
	cout << endl;
	printImg(img, N);

	delete[] img[0];
	delete[] img;

    return 0;
}

