					#include <iostream>
					
					#define int long long
															
					using namespace std;
					
					namespace math{
						
						const int mod = 998244353;
						
						int gcd(int x, int y){
							return x == 0 ? y : math :: gcd(y % x, x);
						}
						
						int lcm(int x, int y){
							return x * y / math :: gcd(x, y);
						}
						
						int power(int n, int p, int m, int res = 1){
							if(m > 0){
								n %= mod;
							}
							for(; p > 0; p >>= 1){
								if(p & 1){
									if(m > 0){
										res = res * n % mod;
									}
									else{
										res = res * n;
									}
								}
								if(m > 0){
									n = n * n % mod;
								}
								else{
									n = n * n;
								}
							}
							return res;
						}
						
						int inverse(int n){
							return power(n, mod - 2, 1);
						}
						
					}
															
					class Fraction{
						
						int n, d;
						
						public:
						
						Fraction(){
							
						}
						
						Fraction(int x, int y){
							int g = math :: gcd(x, y);
							n = x / g;
							d = y / g;
						}
						
						static void print(Fraction c){
							cout << ((c.n < 0) ^ (c.d < 0) ? "-" : "") << abs(c.n) << "/" << abs(c.d) << endl; 
						}
						
						static int modularInverse(Fraction c){
							return c.n * math :: inverse(c.d) % math :: mod;
						}
						
						Fraction operator +(Fraction c){
							Fraction store;
							int cd = math :: lcm(d, c.d);
							store.n = n * cd / d + c.n * cd / c.d;
							store.d = cd;
							
							int g = math :: gcd(store.n, store.d);
							store.n /= g;
							store.d /= g;
							
							return store;
						}

						Fraction operator -(Fraction c){
							Fraction store;
							int cd = math :: lcm(d, c.d);
							store.n = n * cd / d - c.n * cd / c.d;
							store.d = cd;
							
							int g = math :: gcd(store.n, store.d);
							store.n /= g;
							store.d /= g;
							
							return store;
						}

						Fraction operator *(Fraction c){
							Fraction store;
							store.n = n * c.n;
							store.d = d * c.d;

							int g = math :: gcd(store.n, store.d);
							store.n /= g;
							store.d /= g;
							
							return store;
						}

						Fraction operator /(Fraction c){
							Fraction store;
							store.n = n * c.d;
							store.d = d * c.n;

							int g = math :: gcd(store.n, store.d);
							store.n /= g;
							store.d /= g;
							
							return store;
						}
					
					};
					
					void solve(void){
						Fraction a(11, 2);
						Fraction b(-10, 33);
						
						Fraction :: print(a + b);
						Fraction :: print(a - b);
						Fraction :: print(b * a);
						Fraction :: print(a / b);
						
						Fraction :: print(Fraction(4, 28) / Fraction(7, 2));
						
						cout << Fraction :: modularInverse(Fraction(1, 4)) << endl;
					}
					
					signed main() {
					int t = 1; 
					while(t--){
					    solve();
					}	
					
					    return 0;
					}
