// exponenciacao rapida e recorrencia linear
// aula-base: https://www.youtube.com/watch?v=srXWcQt6q10
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

// EXPONENCIACAO RAPIDA
long long fast_exp_rec (long long base, long long exp) {
	if (exp == 0)
		return 1;

	long long answer = fast_exp_rec(base, exp/2);
	answer *= answer;

	if (exp % 2 == 1)
		answer *= base;

	return answer;
}

long long fast_exp_it (long long base, long long exp) {
	// na versao iterativa, vamos dividir o expoente em potencias de 2
	// 2^10 = 2^(8+2) = 2^8 * 2^2, por exemplo
	// assim, olhamos para a representacao binaria do numero 
	long long answer = 1;

	while (exp > 0) {

		if (exp % 2 == 1) 
			answer *= base; 
			// multiplicamos os produtos por 2^exp
			// para cada expoente potencias de 2

		base *= base; // caminha pelas potencias de 2
		exp /= 2;	
	}	

	return answer;
}

// RECORRENCIA LINEAR

typedef vector< vector<int> > matrix;

matrix operator* (matrix &a, matrix &b) {
	matrix result;
	int i, j, k;

	result.resize(a.size());
	for (i = 0; i < a.size(); i++) {
		result[i].resize(b.size());

		for (j = 0; j < b.size(); j++) {
			
			result[i][j] = 0;
			for (k = 0; k < b.size(); k++) 
				result[i][j] += a[i][k] * b[k][j];
		}
	}

	return result;

}

matrix operator^ (matrix &a, long long exp) {
	matrix result;

	if (exp == 1)
		return a;

	result = a ^ exp/2;
	result = result * result;

	if(exp % 2 == 1)
		result =  result * a;

	return result;
}

// o algo de recorrencias lineares tem aplicacao em funcoes lineares
// que dependem de estados anteriores de forma linear
// fibonacci eh um exemplo
long long fib_rec_linear (int number) {
	matrix answer; 
	// eh necessaria uma matriz de transformacao T
	// a dimensao eh o numero de estados anteriores
	matrix T = {{1, 1}, {1, 0}};
	matrix base = {{0}, {1}};

	answer = T^number;
	answer = answer * base;

	return answer[0][0];
}

// programacao dinamica para comparar resultado
// source: https://www.geeksforgeeks.org/program-for-nth-fibonacci-number/
long long fib_DP(long long n) { 
    if (n <= 1) 
        return n; 
    return fib_DP(n-1) + fib_DP(n-2); 
} 


int main() {
	long long base = 15, exp = 4;
	clock_t begin_time; 

	cout.precision(6);
	cout.setf(ios::fixed);

	cout << "Base 15, exp 4. Resposta esperada: 50625" << endl;
	cout << "com funcao recursiva: " << fast_exp_rec(base, exp) << endl;
	cout << "com funcao iterativa: " << fast_exp_it(base, exp) << "\n\n";

	cout << "fibonacci de 40";
	begin_time = clock();
	cout << "com recursao linear: " << fib_rec_linear(40) << " com tempo " << double(clock() - begin_time)/CLOCKS_PER_SEC << endl;
	begin_time = clock();
	cout << "com programacao dinamica: " << fib_DP(40) << " com tempo " << double(clock() - begin_time)/CLOCKS_PER_SEC <<  endl;

	return 0;
}