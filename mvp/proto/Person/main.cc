#include "person.pb.h"

int main() {
    Person person;
    person.set_id(123);
    person.set_name("Mark");
    person.set_email("mark@example.com");

    // 序列化到字符串
    std::string serialized_data;
    person.SerializeToString(&serialized_data);

    // 從字符串反序列化
    Person new_person;
    new_person.ParseFromString(serialized_data);

    std::cout << "Name: " << new_person.name() << std::endl;
    return 0;
}
