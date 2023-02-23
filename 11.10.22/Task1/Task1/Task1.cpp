#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

struct application {
    char date[15];                // дата
    char time[10];                 // время
    char tiker[20];               // тикер
    char type_of_application[10];  // тип заявки
    int count;                    // количество
    double price;                  // цена
    int ID;
};

struct DataBase {
    int amount;         // количество заявок
    int max_amount;     // фиксирование максимума
    application* base;  // "список" заявок
};


std::istream& operator>>(std::istream& in,
    application& request) {  // in for applications
    in >> request.date;
    in.ignore();
    in.getline(request.time, 10, ',');
    in.ignore();
    in.getline(request.tiker, 20, ',');
    in.getline(request.type_of_application, 10, ',');
    if (request.type_of_application[0] == ' ') {
      for (int j = 1; request.type_of_application[j - 1] = request.type_of_application[j];++j);
    }
    in >> request.count;
    in.ignore();
    in >> request.price;
    return in;
}

void Print_Date(char* Date, std::ostream& out) {

    int size = 0;
    for (int i = 0; Date[i]; ++i) {
      ++size;
    }

    int i = 0;
    while (Date[i] != '.') {
      ++i;
    }

    int j = i + 1;
    while (Date[j] != '.') {
      ++j;
    }
    j -= (i + 1);

    int k = size - 2 - i - j;
    if (k == 1) {
      out << Date[i + j + 2] << '.';
    } else if (k == 2) {
      out << Date[i + j + 2] << Date[i + j + 3] << '.';
    } else if (k == 3) {
      out << Date[i + j + 2] << Date[i + j + 3] << Date[i + j + 4] << '.';
    } else if (k == 4) {
      out << Date[i + j + 2] << Date[i + j + 3] << Date[i + j + 4] 
                << Date[i + j + 5] << '.';
    }

    if (j == 1) {
      out << Date[i + 1] << '.';
    } else if (j == 2) {
      out << Date[i + 1] << Date[i + 2] << '.';
    }

    if (i == 1) {
      out << Date[0];
    } else if (i == 2) {
      out << Date[0] << Date[1];
    }

}

bool Checking_the_DATE(char* Date) {
    int DotNum = 0;

    int size = 0;
    for (int i = 0; Date[i]; ++i) {
      ++size;
    }

    for (int i = 0; i < size; ++i) {
      if (Date[i] == '.') {
        DotNum += 1;
      }
    }
    if (DotNum != 2) {
      std::cout << "Wrong date format: " << Date << std::endl;
      return false;
    }
    for (int i = 0; i < size; ++i) {
      if (Date[i] != '.' && (Date[i] < '0' || Date[i] > '9')) {
        std::cout << "Wrong date format: " << Date << std::endl;
        return false;
      }
    }

    int i = 0;
    while (Date[i] != '.') {
      ++i;
    }

    if (i < 1) {
      std::cout << "Wrong date format: " << Date << std::endl;
      return false;
    }
    if (i > 2) {
      std::cout << "Day value is invalid: ";
      for (int pos = 0; pos < size; ++pos) {
        if (Date[pos] == '.') {
          break;
        }
        std::cout << Date[pos];
      }
      std::cout << std::endl;
      return false;
    }

    int j = i + 1;
    while (Date[j] != '.') {
      ++j;
    }

    j -= (i + 1);
    if (j < 1) {
      std::cout << "Wrong date format: " << Date << std::endl;
      return false;
    }
    if (j > 2) {
      std::cout << "Month value is invalid: ";
      for (int pos = j; pos < size; ++pos) {
        if (Date[pos] == '.') {
          break;
        }
        std::cout << Date[pos];
      }
      std::cout << std::endl;
      return false;
    }

    int k = size - 2 - i - j;
    if (k < 1 || k > 4) {
      std::cout << "Wrong date format: " << Date << std::endl;
      return false;
    }

    int d = 0;
    if (i == 1) {
      d = (Date[0] - '0');
    } else if (i == 2) {
      d = (Date[0] - '0') * 10 + (Date[1] - '0');
    }

    int m = 0;
    if (j == 1) {
      m = (Date[i+1] - '0');
    } else if (j == 2) {
      m = (Date[i+1] - '0') * 10 + (Date[i + 2] - '0');
    }

    int y = 0;
    if (k == 1) {
      y = (Date[i + j + 2] - '0');
    } else if (k == 2) {
      y = (Date[i + j + 2] - '0') * 10 +
          (Date[i + j + 3] - '0');
    } else if (k == 3) {
      y = (Date[i + j + 2] - '0') * 100 +
          (Date[i + j + 3] - '0') * 10 +
          (Date[i + j + 4] - '0');
    } else if (k == 4) {
      y = (Date[i + j + 2] - '0') * 1000 +
          (Date[i + j + 3] - '0') * 100 +
          (Date[i + j + 4] - '0') * 10 +
          (Date[i + j + 5] - '0');
    }

    if (y == 0) {
      std::cout << "Wrong date format: " << Date << std::endl;
      return false;
    }
    if (m < 1 || m > 12) {
      std::cout << "Month value is invalid: " << m << std::endl;
      return false;
    }
    if ((m == 1 || m == 3 || m == 5 || m == 7 || m == 8 || m == 10 ||
         m == 12) &&
        (d < 1 || d > 31)) {
      std::cout << "Day value is invalid: " << d << std::endl;
      return false;
    }
    if ((m == 4 || m == 6 || m == 9 || m == 11) && (d < 1 || d > 30)) {
      std::cout << "Day value is invalid: " << d << std::endl;
      return false;
    }

    if (((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0)) && (m == 2) &&
        (d < 1 || d > 29)) {
      std::cout << "Day value is invalid: " << d << std::endl;
      return false;
    }
    if (((y % 4 != 0 || y % 100 == 0) && (y % 400 != 0)) && (m == 2) &&
        (d < 1 || d > 28)) {
      std::cout << "Day value is invalid: " << d << std::endl;
      return false;
    }

    return true;
}

bool Checking_the_TIME(char* Time) {
    int ColonNum = 0;

    int size = 0;
    for (int i = 0; Time[i]; ++i) {
      ++size;
    }

    for (int i = 0; i < size; ++i) {
      if (Time[i] == ':') {
        ColonNum += 1;
      }
    }
    if (ColonNum != 2) {
      std::cout << "Wrong time format: " << Time << std::endl;
      return false;
    }
    for (int i = 0; i < size; ++i) {
      if (Time[i] != ':' && (Time[i] < '0' || Time[i] > '9')) {
        std::cout << "Wrong time format: " << Time << std::endl;
        return false;
      }
    }

    int i = 0;
    while (Time[i] != ':') {
      ++i;
    }

    if (i < 1) {
      std::cout << "Wrong time format: " << Time << std::endl;
      return false;
    }
    if (i > 2) {
      std::cout << "Time value is invalid: " << Time << std::endl;
      return false;
    }

    int j = i + 1;
    while (Time[j] != ':') {
      ++j;
    }

    j -= (i + 1);
    if (j < 1) {
      std::cout << "Wrong time format: " << Time << std::endl;
      return false;
    }
    if (j > 2) {
      std::cout << "Time value is invalid: " << Time << std::endl;
      return false;
    }

    int k = size - 2 - i - j;
    if (k < 1) {
      std::cout << "Wrong time format: " << Time << std::endl;
      return false;
    }
    if (k > 2) {
      std::cout << "Time value is invalid: " << Time << std::endl;
      return false;
    }

    int h = 0;
    if (i == 1) {
      h = (Time[0] - '0');
    } else if (i == 2) {
      h = (Time[0] - '0') * 10 + (Time[1] - '0');
    }

    int m = 0;
    if (j == 1) {
      m = (Time[i + 1] - '0');
    } else if (j == 2) {
      m = (Time[i + 1] - '0') * 10 + (Time[i + 2] - '0');
    }

    int sec = 0;
    if (k == 1) {
      sec = (Time[i + j + 2] - '0');
    } else if (k == 2) {
      sec = (Time[i + j + 2] - '0') * 10 + (Time[i + j + 3] - '0');
    }

    if (sec < 0 || sec > 59) {
      std::cout << "Time value is invalid: " << Time << std::endl;
      return false;
    }
    if (m < 0|| m > 59) {
      std::cout << "Time value is invalid: " << Time << std::endl;
      return false;
    }
    if (h < 0 || h > 23) {
      std::cout << "Time value is invalid: " << Time << std::endl;
      return false;
    }

    return true;
}

bool Checking_the_TYPE_OF_APPLICATION(char* Type_of_application) {
    if (strcmp(Type_of_application, "buy") == 0) {
      return true;
    }
    if (strcmp(Type_of_application, "sell") == 0) {
      return true;
    }
    std::cout << "Unknown command: " << Type_of_application << std::endl;
    return false;
}

bool equals(application x, application y) {
    int day_x = atoi(strtok(x.date, "."));
    int month_x = atoi(strtok(NULL, "."));
    int year_x = atoi(strtok(NULL, "."));

    int day_y = atoi(strtok(y.date, "."));
    int month_y = atoi(strtok(NULL, "."));
    int year_y = atoi(strtok(NULL, "."));

    if (year_x == year_y && month_x == month_y && day_x == day_y) {
      return true;
    }
    return false;
}

bool equal_prices(application x, application y) {
    if (x.price == y.price) {
      return true;
    }

    return false;
}

bool compare_price(application x, application y) {
    if (x.price >= y.price) {
      return false;
    }

    return true;
}

bool compare_type_of_application(application x, application y) {
    if (strcmp(x.type_of_application, "buy") == 0 &&
        strcmp(y.type_of_application, "sell") == 0) {
      return true;
    }

    return false;
}

bool compare_date(application x, application y) {
    int day_x = atoi(strtok(x.date, "."));
    int month_x = atoi(strtok(NULL, "."));
    int year_x = atoi(strtok(NULL, "."));

    int day_y = atoi(strtok(y.date, "."));
    int month_y = atoi(strtok(NULL, "."));
    int year_y = atoi(strtok(NULL, "."));

    if (year_x > year_y) {
      return true;
    }
    if (year_x == year_y && month_x > month_y) {
      return true;
    }
    if (year_x == year_y && month_x == month_y && day_x > day_y) {
      return true;
    }
    return false;
}

bool compare_time(application x, application y) {
    int hour_x = atoi(strtok(x.time, ":"));
    int minutes_x = atoi(strtok(NULL, ":"));
    int sec_x = atoi(strtok(NULL, ":"));

    int hour_y = atoi(strtok(y.time, ":"));
    int minutes_y = atoi(strtok(NULL, ":"));
    int sec_y = atoi(strtok(NULL, ":"));

    int all_sec_x = hour_x * 3600 + minutes_x * 60 + sec_x;
    int all_sec_y = hour_y * 3600 + minutes_y * 60 + sec_y;

    if (all_sec_x > all_sec_y) {
      return true;
    }

    return false;
}

bool equal_time(application x, application y) {
    int hour_x = atoi(strtok(x.time, ":"));
    int minutes_x = atoi(strtok(NULL, ":"));
    int sec_x = atoi(strtok(NULL, ":"));

    int hour_y = atoi(strtok(y.time, ":"));
    int minutes_y = atoi(strtok(NULL, ":"));
    int sec_y = atoi(strtok(NULL, ":"));

    int all_sec_x = hour_x * 3600 + minutes_x * 60 + sec_x;
    int all_sec_y = hour_y * 3600 + minutes_y * 60 + sec_y;

    if (all_sec_x == all_sec_y) {
      return true;
    }

    return false;
}

void SORTING_TO_PRINT_OUT(DataBase& DB) {
    for (int i = 0; i < DB.amount ; ++i) {
      for (int j = 0; j < DB.amount - 1; ++j) {
        if (compare_date(DB.base[j], DB.base[j + 1])) {
          application tmp = DB.base[j+1];
          DB.base[j+1] = DB.base[j];
          DB.base[j] = tmp;
        } else if (equals(DB.base[j], DB.base[j+1])) {
          if (compare_time(DB.base[j], DB.base[j+1])) {
            application tmp = DB.base[j+1];
            DB.base[j+1] = DB.base[j];
            DB.base[j] = tmp;
          } else if (equal_time(DB.base[j], DB.base[j + 1])) {
            if (DB.base[j].ID > DB.base[j + 1].ID) {
              application tmp = DB.base[j + 1];
              DB.base[j + 1] = DB.base[j];
              DB.base[j] = tmp;
            }
          }
        }
      }
    }
}

void SORT_BY_PRICE(application* arr, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n - 1; ++j) {
            if (compare_price(arr[j], arr[j+1])) {
                application tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            } else if (equal_prices(arr[j], arr[j+1])) {
                if (compare_type_of_application(arr[j], arr[j+1])) {
                    application tmp = arr[j + 1];
                    arr[j + 1] = arr[j];
                    arr[j] = tmp;
                } else if (strcmp(arr[j].type_of_application,"sell") == 0 &&
                           strcmp(arr[j+1].type_of_application, "sell") == 0) {
                    if (compare_date(arr[j+1], arr[j])) {
                        application tmp = arr[j + 1];
                        arr[j + 1] = arr[j];
                        arr[j] = tmp;
                    } else if (equals(arr[j], arr[j+1])) {
                        if (compare_time(arr[j+1], arr[j])) {
                            application tmp = arr[j + 1];
                            arr[j + 1] = arr[j];
                            arr[j] = tmp;
                        }
                    }
                } else if (strcmp(arr[j].type_of_application, "buy") == 0 &&
                           strcmp(arr[j+1].type_of_application, "buy") == 0) {
                    if (compare_date(arr[j], arr[j+1])) {
                        application tmp = arr[j + 1];
                        arr[j + 1] = arr[j];
                        arr[j] = tmp;
                    } else if (equals(arr[j], arr[j+1])) {
                      if (compare_time(arr[j], arr[j+1])) {
                          application tmp = arr[j + 1];
                          arr[j + 1] = arr[j];
                          arr[j] = tmp;
                      }
                    }
                }
            }
        }
    }
}

void DELETE(DataBase& DB) {     //delete-ing DB
    int IDNDEX;
    std::cin >> IDNDEX;
    std::cin.ignore();
    int j = 0;
    for (int i = 0; i < DB.amount; ++i) {
        if (DB.base[i].ID == IDNDEX) {
            j = i;
            break;
        }
    }
    DB.base[j] = DB.base[DB.amount - 1];
    /*
    for (int i = j; i < DB.amount - 1; ++i) {
      DB.base[i] = DB.base[i + 1];
    }
    */
    --DB.amount;
}

void CLEAR(DataBase& DB) {  // clear-ing DB
    int count_of_zeroes = 0;
    for (int i = 0; i < DB.amount; ++i) {
        if (DB.base[i].count == 0) {
            count_of_zeroes += 1;
        }
    }
    while(count_of_zeroes > 0) {
        for (int i = 0; i < DB.amount; ++i) {
            if (DB.base[i].count == 0) {
                for (int j = i; j < DB.amount - 1; ++j) {
                    DB.base[j] = DB.base[j + 1];
                }
                --count_of_zeroes;
                --DB.amount;
                break;
            }
        }
    }
}

void Calculations(DataBase& DB) { 
    application now = DB.base[DB.amount - 1];
    if (strcmp(now.type_of_application, "sell") == 0) {
        for (int i = 0; i < DB.amount - 1; ++i) {
            for (int j = 0; j < DB.amount - 2; ++j) {
                if (compare_price(DB.base[j], DB.base[j + 1])) {
                    application tmp = DB.base[j + 1];
                    DB.base[j + 1] = DB.base[j];
                    DB.base[j] = tmp;
                }
            }
        }
        for (int i = 0; i < DB.amount - 1; ++i) {
            if (strcmp(DB.base[i].type_of_application, "buy") == 0 &&
                DB.base[i].price >= now.price && DB.base[i].price != 0 &&
                strcmp(DB.base[i].tiker, now.tiker) == 0) {
                if (DB.base[i].count > now.count) {
                    DB.base[i].count -= now.count;
                    now.count = 0;
                    break;
                } else if (DB.base[i].count < now.count) {
                    now.count -= DB.base[i].count;
                    DB.base[i].count = 0;
                } else {
                    DB.base[i].count = 0;
                    now.count = 0;
                    break;
                }
            }
        }

        DB.base[DB.amount - 1].count = now.count;
    }
    if (strcmp(now.type_of_application, "buy") == 0) {
        for (int i = 0; i < DB.amount - 1; ++i) {
            for (int j = 0; j < DB.amount - 2; ++j) {
                if (compare_price(DB.base[j+1], DB.base[j])) {
                    application tmp = DB.base[j + 1];
                    DB.base[j + 1] = DB.base[j];
                    DB.base[j] = tmp;
                }
            }
        }
        for (int i = 0; i < DB.amount - 1; ++i) {
            if (strcmp(DB.base[i].type_of_application, "sell") == 0 &&
                DB.base[i].price <= now.price && DB.base[i].price != 0 &&
                strcmp(DB.base[i].tiker, now.tiker) == 0) {
                if (DB.base[i].count > now.count) {
                    DB.base[i].count -= now.count;
                    now.count = 0;
                    break;
                } else if (DB.base[i].count < now.count) {
                    now.count -= DB.base[i].count;
                    DB.base[i].count = 0;
                } else {
                    DB.base[i].count = 0;
                    now.count = 0;
                    break;
                }
            }
        }
        DB.base[DB.amount - 1].count = now.count;
    }
}

void ADD(DataBase& DB, int& sum) {  // add DB
    if (DB.amount == DB.max_amount) {
        if (DB.max_amount > 0) {
            DB.max_amount *= 2;
        } else {
            DB.max_amount = 1;
        }
        application* present = new application[DB.max_amount];
        for (int i = 0; i < DB.amount; ++i) {
            present[i] = DB.base[i];
        }
        if (DB.base != nullptr) {
            delete[] DB.base;
        }
        DB.base = present;
    }
    ++sum;
    std::cin >> DB.base[DB.amount];
    DB.base[DB.amount].ID = sum;

    if (!Checking_the_DATE(DB.base[DB.amount].date)) {
        --sum;
    } else if (!Checking_the_TIME(DB.base[DB.amount].time)) {
        --sum;
    } else if (!Checking_the_TYPE_OF_APPLICATION(DB.base[DB.amount].type_of_application)) {
        --sum;
    } else {
        ++DB.amount;
        Calculations(DB);
    }

}

void PRINT(DataBase& DB) {  // print-ing DB
    SORTING_TO_PRINT_OUT(DB);
    for (int i = 0; i < DB.amount; ++i) {
        std::cout << DB.base[i].ID << ", ";
        Print_Date(DB.base[i].date, std::cout);
        std::cout << ' ' << DB.base[i].time << ", " << DB.base[i].tiker << ", "
                  << DB.base[i].type_of_application << ", " << DB.base[i].count
                  << ", " << std::fixed << std::setprecision(2)
                  << DB.base[i].price << std::endl;
    }
}

void LOAD(DataBase& DB, const char file_name[]) {  // load-ing DB
    std::ifstream input_file(file_name, std::ios_base::binary);
    if (!input_file.is_open()) {
        std::cout << "Can not open database" << std::endl;
        return;
    }
    int amount;
    input_file.read((char*)&amount, sizeof(amount));
    if (DB.base != nullptr) {
        delete[] DB.base;
    }
    DB.base = new application[amount];
    DB.amount = amount;
    DB.max_amount = amount;
    input_file.read((char*)DB.base, sizeof(application) * DB.amount);
    input_file.close();
}

void DOM(DataBase& DB,
         const char* tiker_to_check) {  // print tiker_to_check and sort it
    application* arr = new application[DB.amount];
    int ind = 0;
    for (int i = 0; i < DB.amount; ++i) {
        bool flag = true;
        char* for_checking = DB.base[i].tiker;
        for (int j = 0; for_checking[j]; ++j) {
            if (std::tolower(for_checking[j]) != static_cast<int>(tiker_to_check[j])) {
                flag = false;
                break;
            }
        }
        if (DB.base[i].count != 0 && flag) {
            arr[ind] = DB.base[i];
            ++ind;
        }
    }
    int count_of_not_a_zero = ind;
    SORT_BY_PRICE(arr, count_of_not_a_zero);
    for (int i = 0; i < count_of_not_a_zero; ++i) {
        std::cout << arr[i].type_of_application << ", " << std::fixed
                  << std::setprecision(2) << arr[i].price << ", "
                  << arr[i].count << ", ";
        Print_Date(arr[i].date, std::cout);
        std::cout << ' ' << arr[i].time << std::endl;
    }
    delete[] arr;
}
void SAVE(const DataBase& DB, const char file_name[]) {      //save DB
    std::ofstream output_file(file_name, std::ios_base::binary);
    if (!output_file.is_open()) {
        std::cout << "Can not write to file" << std::endl;
        return;
    }
    output_file.write((const char*)&DB.amount, sizeof(DB.amount));
    output_file.write((const char*)DB.base, sizeof(application) * DB.amount);
    output_file.close();
}

void EXPORT(DataBase& DB, const char file_name[]) {  // export DB
    std::ofstream output_file(file_name, std::ios_base::binary);
    if (!output_file.is_open()) {
        std::cout << "Can not write to file" << std::endl;
        return;
    }
    SORTING_TO_PRINT_OUT(DB);
    for (int i = 0; i < DB.amount; ++i) {
        Print_Date(DB.base[i].date, output_file);
        output_file << ' ' << DB.base[i].time << ", " << DB.base[i].tiker
                    << ", " << DB.base[i].type_of_application << ", "
                    << DB.base[i].count << ", " << std::fixed
                    << std::setprecision(2) << DB.base[i].price<< std::endl;
    }
    output_file.close();
}

int main() {
  DataBase DB = {0, 0, nullptr};
  char command[256];
  int sum = 0;
  while (true) {
    std::cout << "> ";
    std::cin >> command;

    if (strcmp(command, "load") == 0) {  // load
      char file_name[256];
      std::cin >> file_name;
      LOAD(DB, file_name);

    } else if (strcmp(command, "save") == 0) {  // save
      char file_name[256];
      std::cin >> file_name;
      SAVE(DB, file_name);

    } else if (strcmp(command, "add") == 0) {  // add
      ADD(DB, sum);

    } else if (strcmp(command, "delete") == 0) {  // delete
      DELETE(DB);

    } else if (strcmp(command, "clear") == 0) {  // clear
      CLEAR(DB);

    } else if (strcmp(command, "print") == 0) {  // print
      PRINT(DB);

    } else if (strcmp(command, "dom") == 0) {  // dom
      char tiker_to_check[20];
      std::cin.ignore();
      std::cin.getline(tiker_to_check, 20);

      for (int i = 0; tiker_to_check[i]; ++i) {
          tiker_to_check[i] = std::tolower(tiker_to_check[i]);
      }

      DOM(DB, tiker_to_check);

    } else if (strcmp(command, "export") == 0) {  // export
      char file_name[256];
      std::cin >> file_name;
      EXPORT(DB, file_name);

    } else if (strcmp(command, "quit") == 0) {  // quit
      delete[] DB.base;
      break;

    } else {
      std::cout << "Unknown command: " << command << std::endl;
      while (std::cin.peek() != '\n') {
          char str[256];
          std::cin >> str;
      }
    }
  }
  return 0;
}
