using namespace std;

string set_spaces(int spaceQ){ // Табуляция для красивого вывода))
    string result = "";
    for (int i = 0; i < spaceQ; i++){
        result += " ";
    }
    return result;
}

double tailersRow_N(double x, int n){
    double summand = (x-1) / (x+1);
    double result = summand;
    for(int i = 3; i <= n * 2; i += 2){
        summand *= ((x-1)*(x-1))/((x+1)*(x+1));
        result += summand/i;
    }
    return result*2;
}

vector <double> tailersRow_E(double x, double e){
    double i = 1;
    double summand = (x-1) / (x+1);
    double result = summand;
    while(abs(summand/i) >= e){
        summand *= ((x-1)*(x-1))/((x+1)*(x+1));
        result += summand / i;
        i++;
    }
    return { result*2, i };
}
