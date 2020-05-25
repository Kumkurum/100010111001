#include <iostream>

struct countdown {
	int X;
	int Y;
	countdown(int x = 0, int y = 0) {
		X = x;
		Y = y;
	}
};
void Fu(countdown* C, int N, int n) {
	int iter = 1;
	int _n;
	for (int i = 0; i < N; i++) {
		if (C[i].Y == C[i + 1].Y) {
			for (int j = i; j < N; j++) {
				if (C[j].Y == C[j + 1].Y)
					iter++;
				else
					break;
			}
		}
		std::cout << "( " << C[i].X << "," << C[i].Y << " ), ";
		if (iter > 1) {
			_n = iter / n;
			if (_n) {
				for (int k = 0; k < _n; k++) {
					std::cout << "(" << C[i + n * _n - 1].X << ", " << C[i + n * _n - 1].Y << "), ";
				}
			}
			if ((i + n * _n - 1) != (i + iter - 1))
				std::cout << "( " << C[i + iter - 1].X << "," << C[i + iter - 1].Y << " ), ";
		}
		i = i + iter - 1;
		iter = 1;
	}
}
