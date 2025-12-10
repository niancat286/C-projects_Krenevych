

#include <iostream>
#include <string>
#include <queue>


using namespace std;



class Auto {
    public:
    string name;
    string model;
    string number;
    string owner_id;
    double repair_cost;

    Auto() : repair_cost(0.0) {}

    Auto(const string& name_in, const string& model_in,
         const string& number_in, const string& owner_id_in,
         double cost_in)
        : name(name_in), model(model_in), number(number_in),
          owner_id(owner_id_in), repair_cost(cost_in) {}

    void input_data() {
        cout << "Enter name: ";
        cin >> name;
        cout << "Enter model: ";
        cin >> model;
        cout << "Enter number: ";
        cin >> number;
        cout << "Enter owner id: ";
        cin >> owner_id;
    }


    void input_repair_cost() {
        cout << "Enter repair cost: ";
        if (!(cin >> repair_cost)) {
            cerr << "Error entering repair cost. repair cost = 0.0." << endl;
            repair_cost = 0.0;
            cin.clear();
            cin.ignore(10000, '\n');
        }
    }

    void output_data() const {
        cout << "  [" << name << " " << model << " | " << number << "]"
             << " ID: " << owner_id
             << " | repair cost: " << repair_cost << endl;
    }

    bool operator<(const Auto& other) const {
        return repair_cost < other.repair_cost;
    }

};


void simulate_repair_queue_5_cars() {
    priority_queue<Auto> repair_orders;

    repair_orders.emplace("Audi", "A4", "AA1111BB", "O100", 5000.00);

    repair_orders.emplace("BMW", "X5", "BB2222CC", "O200", 20000.00);

    repair_orders.emplace("Ford", "Focus", "FF3333DD", "O300", 1500.00);

    repair_orders.emplace("Mazda", "3", "MM4444EE", "O400", 4900.00);

    repair_orders.emplace("Toyota", "Camry", "TT5555FF", "O500", 10000.00);

    int order_rank = 1;

    while (!repair_orders.empty()) {

        Auto highest_priority_auto = repair_orders.top();
        repair_orders.pop();

        cout << order_rank++ << ". Обслуговується: ";
        highest_priority_auto.output_data();
        cout << endl;
    }
}

void test1() {
    priority_queue<Auto> repair_q;

    int num_orders;
    cout << "\nHow much orders do you want to add (N): ";
    if (!(cin >> num_orders) || num_orders <= 0) num_orders = 3;
    for (int i = 0; i < num_orders; ++i) {
        cout << "\n--- Order #" << i + 1 << " ---\n";
        Auto new_auto;
        new_auto.input_data();
        new_auto.input_repair_cost();

        repair_q.push(new_auto);
    }


    int order_rank = 1;

    while (!repair_q.empty()) {

        Auto autoN1 = repair_q.top();

        cout << "queue №" << order_rank++ << ": ";
        autoN1.output_data();

        repair_q.pop();
    }
}


int main() {

    //test1();
    simulate_repair_queue_5_cars();

    return 0;
}



