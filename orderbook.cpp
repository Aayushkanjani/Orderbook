#include<iostream>
#include<vector>

using namespace std;

struct tape{
    std::string time;
    double price;
    double volume;
    double volume_ma=0.0;
    double price_change=0.0;
};

class HFT{

    private:
        double cash;
        double position;

    public:

        HFT(double initial_cash):cash(initial_cash),position(0){

        }

        void readTape(vector<tape>&ListofTrades){

            //Compute Volume Moving Average and Price Change

            for(int i=4;i<ListofTrades.size();i++){

                double sum=0.0;
                for(int j=i-4;j<=i;j++){
                    sum+=ListofTrades[j].price;
                }

                ListofTrades[i].volume_ma=sum/5.0;

            }

            for(int i=1;i<ListofTrades.size();i++){
                ListofTrades[i].price_change=(ListofTrades[i].price-ListofTrades[i-1].price)/ListofTrades[i-1].price;
            }

        }

        void Transact(vector<tape>ListofTrades){

            for(int i=0;i<ListofTrades.size();i++){
                
                // Skip rows without MA or price_change data
                if(ListofTrades[i].volume_ma==0.0 || ListofTrades[i].price_change==0.0) continue;
                
                //Buy
                if(ListofTrades[i].price_change>0 && cash>ListofTrades[i].price){
                    cash-=ListofTrades[i].price;
                    position+=1;

                    cout<<"Buyed at "<<ListofTrades[i].price<<'\n';
                }

                //sell
                if(ListofTrades[i].price_change<0 && position>0){
                    cash+=ListofTrades[i].price;
                    position-=1;

                    cout<<"Sold at "<<ListofTrades[i].price<<'\n';
                }

            }
        }


        void runTape(vector<tape>ListofTrades){
            readTape(ListofTrades);
            Transact(ListofTrades);

            cout<<"Final cash "<<cash<<" Final Position: "<<position<<'\n';
        }

};

int main(){
    vector<tape> trades={
        {"2024-01-01 00:00", 100, 1000},
        {"2024-01-01 00:01", 101, 1500},
        {"2024-01-01 00:02", 102, 1200},
        {"2024-01-01 00:03", 101, 1300},
        {"2024-01-01 00:04", 100, 1400},
        {"2024-01-01 00:05", 99, 1100},
        {"2024-01-01 00:06", 98, 1600},
        {"2024-01-01 00:07", 97, 1700},
        {"2024-01-01 00:08", 98, 1800},
        {"2024-01-01 00:09", 99, 1500}
    };

    

    //HFT(1500.00).runTape(trades);
    // or

    HFT hrt(1500.00);

    hrt.runTape(trades);

}