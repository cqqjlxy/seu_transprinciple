/*
 * File: transportprinciple_project.cpp
 * Author: 梁星宇
 * Student Number: 12021108
 * Email: cqqjlxy@gmail.com
 * Description: 使用高斯-赛德尔迭代法计算习题6-8
 * Created on: Dec 29, 2023
 * Last modified: Jan 1, 2024
 */

#include <cmath>
#include <iostream>
using namespace std;

// 常量：用来规定最大的迭代次数
const int MAX_ITERATIONS = 100;

// 精度要求 (°C)
const double CONVERGENCE_CRITERION = 1e-14;

// 重载一下<<，方便用于输出每个节点的温度迭代结果

ostream& operator << (ostream& cout, double grids[5][5]) {
	for (int i = 0; i < 5; ++i) {
		for (int j = 0; j < 5; ++j) {
			cout << grids[i][j] << "\t";
		}
		cout << endl;
	}
	return cout;
}

int main() {
	// 初始化网格，节点猜测最初的温度为0°C
	/*
	[150][180][200][180][150]
	[180][(1)][(2)][(3)][180]
	[200][(4)][(5)][(6)][200]
	[180][(7)][(8)][(9)][180]
	[150][180][200][180][150]
	*/
	double grids[5][5] = {
			{150, 180, 200, 180, 150},
			{180,   0,   0,   0, 180},
			{200,   0,   0,   0, 200},
			{180,   0,   0,   0, 180},
			{150, 180, 200, 180, 150}
	};

	bool converged = false;

	for (int iter = 0; iter < MAX_ITERATIONS && !converged; ++iter) {
		converged = true;

		// 使用高斯-塞德尔迭代法更新内部节点温度
		for (int i = 1; i < 5 - 1; ++i) {
			for (int j = 1; j < 5 - 1; ++j) {
				double T_old = grids[i][j];
				double T_new = (grids[i - 1][j] + grids[i + 1][j] +
					grids[i][j - 1] + grids[i][j + 1]) / 4.00;

				grids[i][j] = T_new;

				// 检查是否达到收敛条件
				if (fabs(T_old - T_new) > CONVERGENCE_CRITERION) {
					converged = false;
				}
			}
		}

		// 在每次迭代后打印温度网格
		cout << "第" << iter + 1 << "次的迭代结果为：" << endl << grids << endl;
	}

	// 打印最终温度网格
	cout << "迭代后的结果为：" << endl << grids << endl;
	system("pause");
	return 0;
}
