#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

/*----これらの関数を変更する必要はありません----*/
std::vector<std::string> names{"Nick", "Lewis", "Nikos"};

bool contains(const std::string& name, const std::vector<std::string>& list_of_names) {
  return std::find(list_of_names.begin(), list_of_names.end(), name) != list_of_names.end();
}

std::string get_name(const std::string& name, const std::vector<std::string>& list_of_names) {
  if (contains(name, list_of_names)) {
    return name;
  } else {
    return "";
  }
}

void add_name(const std::string& name, std::vector<std::string>& list_of_names) { list_of_names.push_back(name); }

int add_two(int num) { return num + 2; }
double divide_by_two(double num) { return num / 2; }
std::string greeting(const std::string& name, double num) {
  std::string message{"Hello, " + name + ". It is " + std::to_string(num) + " degrees warmer today than yesterday"};
  std::cout << message << std::endl;
  return message;
}

/*----ここにコードを書いてください----*/
/*----難易度: 富士----*/

// `my_assert` をここに定義し、以降のテストに使用してください。

void my_assert(const bool expr, const std::string& msg) {
  if (expr) {
    std::cout << "Passed " << std::endl;
  } else {
    throw std::runtime_error(msg);
    // throw std::string(msg);
  }
  return;
}

// `contains` 用のテスト `test_contains` を作成してください

void test_contains() {
  try {
    my_assert(contains("Nick", names) == true, "output of function 'contains' was not expected");
  } catch (std::runtime_error& e) {
    std::cerr << "Failed: " << e.what() << std::endl;
  }

  try {
    my_assert(contains("Mat", names) == false, "output of function 'contains' was not expected");
  } catch (std::runtime_error& e) {
    std::cerr << "Failed: " << e.what() << std::endl;
  }
}

// `get_name` 用のテスト `test_get_name` を作成してください

void test_get_name() {
  try {
    my_assert(get_name("Nick", names) == "Nick", "output of function 'get_name' was not expected");
  } catch (std::runtime_error& e) {
    std::cerr << "Failed: " << e.what() << std::endl;
  }
}

// `add_name` 用のテスト `test_add_name` を作成してください

void test_add_name() {
  try {
    add_name("Mat", names);
    my_assert(names.back() == "Mat", "Failed to add to the list");
  } catch (std::runtime_error& e) {
    std::cerr << "Failed: " << e.what() << std::endl;
  }
}

// `add_two` 用のテスト `test_add_two` を作成してください

void test_add_two() {
  try {
    my_assert(add_two(2) == 4, "sum was not calculated correctly");
  } catch (std::runtime_error& e) {
    std::cerr << "Failed: " << e.what() << std::endl;
  }
}

// `divide_by_two` 用のテスト `test_divide_by_two` を作成してください

void test_divide_by_two() {
  try {
    my_assert(divide_by_two(2) == 1, "division was not calculated correctly");
  } catch (std::runtime_error& e) {
    std::cerr << "Failed: " << e.what() << std::endl;
  }
}

// `greeting` 用のテスト `test_greeting` を作成してください

void test_greeting() {
  try {
    my_assert(greeting("Kota", 2.0) == "Hello, Kota. It is 2.000000 degrees warmer today than yesterday",
              "output of function 'greeting' was not expected");
    // } catch (std::runtime_error& e) {
    //   std::cerr << "Failed: " << e.what() << std::endl;
    // }
  } catch (const char* msg) {
    std::cerr << "Failed: " << msg << std::endl;
  }
}

/*----難易度: キリマンジャロ----*/

// `my_assert` 用のテスト `test_my_assert_false` を作成し、式がfalseと評価されたときに指定したオプションの `msg`
// を適切に返すかどうかをチェックしてください。

void test_my_assert_false() {
  try {
    my_assert(false, "test error message");
  } catch (std::runtime_error& e) {
    my_assert(std::string(e.what()) == "test error message", "should return a proper message");
  }
}

// `my_assert` 用のテスト `test_my_assert_true`
// を作成し、式がtrueと評価されたときに適切に処理するかどうかをチェックしてください。

void test_my_assert_true() {
  try {
    my_assert(true, "test true case");
  } catch (std::runtime_error& e) {
    my_assert(std::string(e.what()) == "test true case", "should return a proper message");
  }
}

/*----難易度: エベレスト----*/

// 次の式全体をテストする `test_complex_greeting` を `my_assert`
// を使用して作成してください。式がエラーになった場合は、エラーの理由がわかるメッセージを `msg` に指定してください。
// greeting(get_name("Frosty the Snowman", {"Oatmeal", "Prancer", "Rudolph", "Andy"}), divide_by_two(add_two(2)));

void test_complex_greeting() {
  std::string input_member = "Frosty the Snowman";
  // std::string input_member = "Prancer";

  std::string expect = "Hello, " + input_member + ". It is 2.000000 degrees warmer today than yesterday";

  try {
    my_assert(greeting(get_name(input_member, {"Oatmeal", "Prancer", "Rudolph", "Andy"}), divide_by_two(add_two(2))) ==
                  expect,
              input_member + "is not a given member list");
  } catch (std::runtime_error& e) {
    std::cerr << "Failed: " << e.what() << std::endl;
  }
}

int main() {
  test_contains();
  test_get_name();
  test_add_name();
  test_add_two();
  test_greeting();
  test_my_assert_false();
  test_my_assert_true();
  test_complex_greeting();
  return 0;
}