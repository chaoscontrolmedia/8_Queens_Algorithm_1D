#include <iostream>

using std::cin, std::cout, std::endl;

/*this function checks for valid solutions.*/
bool checks(int q[], int r, int c){
    for(int i = 0; i<c; i++){
         if(q[i] == r || abs(c-i) == abs(q[i] -r))
         return false;
    }
    return true;
}



//This function takes in the array, the edge of the board(n), the columns, and the solutions count.
void solve(int q[], int n, int c, int & solve_count){
    if(c == n){
        solve_count++;
        for(int i = 0; i<n; i++){
            cout << q[i] << " ";
        }
        cout << endl;
        return;
    } else{
        for(int r = 0; r<n; r++){
            if(checks(q, r, c)){
                q[c] = r;
                solve(q, n, c+1, solve_count);
                q[c] = -1;
            }
        }
    }

}





//takes the current iteration of the position back one
void backtrack(int q[],  int& c){
    q[c] = -1;
    c--;
}


//The solutions are output in the main function. 

int main(){
    int n = 8; 
    int solve_count = 0;
    int q[8]; 

    for (int i = 0; i < n; i++) {
        q[i] = -1; 
    }

    solve(q, n, 0, solve_count);

    cout << "Total solutions: " << solve_count << endl;

    return 0;

    
}