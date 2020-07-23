#include "Camera.h"  // 선언부의 헤더파일을 불러온다.

Camera::Camera() { limit = 0, name = " "; }  // 기본생성자를 통해 멤버 변수를 초기화한다.

string Camera::getName() { return this->name; }  // private 처리된 name멤버변수를 getter함수를 이용하여 값을 불러온다.
void Camera::setName(string name) { this->name = name; }  // private 처리된 name멤버변수를 setter함수를 이용하여 값을 입력한다.

int Camera::getLimit() { return this->limit; }  // private 처리된 limit멤버변수를 getter함수를 이용하여 값을 불러온다.
void Camera::setLimit(int limit) { this->limit = limit; } // private 처리된 limit멤버변수를 setter함수를 이용하여 값을 입력한다.

Camera::~Camera() {}  // virtual을 이용한 가상 소멸자 정의