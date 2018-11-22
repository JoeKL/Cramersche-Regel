#include "mex.h"
#include "stdio.h"
#include "math.h"


double det_laplace(double* A, int N) {															
	if (N == 1) {
		return A[1];
	}
		
	if (N == 2) {
		return A[1] * A[4] - A[2] * A[3];
	}

	if (N == 3) {
		return ( A[1] * A[5] * A[9] + A[2] * A[6] * A[7] + A[3] * A[4] * A[8] - A[7] * A[5] * A[3] - A[8] * A[6] * A[1] - A[9] * A[4] * A[2] );
	}														
		
	double detFinal = 0;	
	
	for (int i = 1; i <= N; i++) {					
		double B[(N-1)*(N-1)];
		int B_lauf = 1;										
		int row_lauf = 1;									
		for (int j = N + 1; j <= (N*N); j++) {				
			if ( j !=  i+(N*(row_lauf)) ) {					
				B[B_lauf] = A[j];							
				B_lauf++;									
			}												
			else {											
				row_lauf++;								
			}																							
		}													
		detFinal += pow(-1,i-1) * A[i] * det_laplace(B, (N - 1));
	}						
		return detFinal;
}					

void mexFunction (int nlhs, mxArray *plhs[], int nrhs, const mxArray *prhs[])
{	
	
	if( nrhs != 2 || !mxIsDouble(prhs[0]) || mxGetM(prhs[0]) != mxGetN(prhs[0])){
		printf("Param-error");
	}
	
	//Var ini
	double *A, *B, *x;
	int nA, nB;
	double detA;
	
	//ans ini
	plhs[0] = mxCreateDoubleMatrix((int) mxGetM(prhs[0]), 1, mxREAL);
	x = mxGetPr(plhs[0]);
	
	A = mxGetPr(prhs[0]);
	double *tempA;
	tempA = A-(sizeof(double)/8);  //Bitmanipulation: A[0] ==> tempA[1] (spart uns das umschreiben eines Arrays)
	nA = (int) mxGetM(prhs[0]);
	
	
	B = mxGetPr(prhs[1]);
	double *tempB;
	tempB = B-(sizeof(double)/8);  //Bitmanipulation: B[0] ==> tempB[1] (spart uns das umschreiben eines Arrays)
	nB = (int) mxGetM(prhs[1]);
		
			
	detA = det_laplace(tempA, nA);	
	
	double tempAi[nA*nA];
	
	for(int i = 1; i <= nA; i++){
		for(int l = 1; l <=  pow(nA,2); l++){
			tempAi[l] = tempA[l];
		}
		
		for(int j = 1; j <= nA; j++){
			tempAi[j+nA*(i-1)] = tempB[j];
		}
		
		x[i-1] = det_laplace(tempAi, nA)/detA;
	}
}