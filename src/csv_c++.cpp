#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

struct Record {
    std::string field1;
    std::string field2;
    std::string field3;
    std::string field4;
    std::string field5;
    std::string field6;
    std::string field7;
    std::string field8;
    std::string field9;
    // Add more fields as per your CSV structure
};

std::vector<Record> parseCSV(const std::string& filepath) {
    std::vector<Record> records;
    std::ifstream file(filepath);
    
    if (file.is_open()) {
        std::string line;
        while (std::getline(file, line)) {
            std::stringstream ss(line);
            std::string field1, field2, field3, field4, field5, field6, field7, field8, field9;
            std::getline(ss, field1, ',');
            std::getline(ss, field2, ',');
            std::getline(ss, field3, ',');
            std::getline(ss, field4, ',');
            std::getline(ss, field5, ',');
            std::getline(ss, field6, ',');
            std::getline(ss, field7, ',');
            std::getline(ss, field8, ',');
            std::getline(ss, field9, ',');
            records.push_back({field1, field2, field3, field4, field5, field6, field7, field8, field9});
        }
        file.close();
    }
    
    return records;
}

int main() {
    std::vector<Record> records = parseCSV("path_to_your_file.csv");
    for (const auto& record : records) {
        std::cout << "Field1: " << record.field1 << ", Field2: " << record.field2 << "Field3: " << record.field3 << "Field4: " << record.field4 << "Field5: " << record.field5 << "Field6: " << record.field6 << "Field7: " << record.field7 << "Field8: " << record.field8 << "Field9: " << record.field9 << std::endl;
    }
    return 0;
}
