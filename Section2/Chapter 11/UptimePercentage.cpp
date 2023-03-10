#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

// uses a template as to accept any data type
template <typename T> void display(T value);
map<string, vector<double>> load_uptimes(string filename);
void process_uptimes(const map<string, vector<double>> &uptimes);

int main() {
  const string filename = "uptimes.txt";
  cout << "Processing regional uptimes in " << filename << "...\n\n";
  auto uptimes = load_uptimes(filename);

  // if the file is empty
  if (uptimes.empty()) {
    cout << "No data or unable to open file.\n\n";
  } else {
    process_uptimes(uptimes);
  }
}

// displays the value no matter the datatype
template <typename T> void display(T value) { cout << value << "% "; }

map<string, vector<double>> load_uptimes(string filename) {
  map<string, vector<double>> uptimes;
  ifstream datafile(filename); // reads file

  if (datafile) { // if the file exists
    string line;
    while (getline(datafile, line)) {
      istringstream row(line);

      string region;
      row >> region;

      vector<double> times;
      double uptime;
      while (row >> uptime) {
        times.push_back(uptime);
      }
      uptimes[region] = times;
    }
    datafile.close();
  }
  return uptimes;
}

// passes in a map of the region with their list of uptime data about servers
void process_uptimes(const map<string, vector<double>> &uptimes) {
  for (auto p : uptimes) {           // for every key in uptimes
    string region = p.first;         // region
    vector<double> times = p.second; // list of uptimes
    double sum =
        accumulate(times.begin(), times.end(), 0.0); // sum of all teh uptimes

    cout << region;
    cout << "\n\tAvg uptime - " << fixed << setprecision(2);
    cout << (sum / times.size()) << '%';

    cout << "\n\tDaily: " << setprecision(1);
    for_each(times.begin(), times.end(),
             display<double>); // for each valeu with the range display with
                               // datatype double
    cout << endl;
  }

  cout << "\nAvg uptime across all regions - ";
  double uptimeTotal =
      accumulate(uptimes.begin(), uptimes.end(), 0.0, [](double total, auto p) {
        return total + accumulate(p.second.begin(), p.second.end(), 0.0);
      });
  int uptimeCount =
      accumulate(uptimes.begin(), uptimes.end(), 0,
                 [](int count, auto p) { return count + p.second.size(); });
  cout << setprecision(2) << (uptimeTotal / uptimeCount) << "\n\n";
}