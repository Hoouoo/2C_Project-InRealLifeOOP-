#include "Camera.h"  // ������� ��������� �ҷ��´�.

Camera::Camera() { limit = 0, name = " "; }  // �⺻�����ڸ� ���� ��� ������ �ʱ�ȭ�Ѵ�.

string Camera::getName() { return this->name; }  // private ó���� name��������� getter�Լ��� �̿��Ͽ� ���� �ҷ��´�.
void Camera::setName(string name) { this->name = name; }  // private ó���� name��������� setter�Լ��� �̿��Ͽ� ���� �Է��Ѵ�.

int Camera::getLimit() { return this->limit; }  // private ó���� limit��������� getter�Լ��� �̿��Ͽ� ���� �ҷ��´�.
void Camera::setLimit(int limit) { this->limit = limit; } // private ó���� limit��������� setter�Լ��� �̿��Ͽ� ���� �Է��Ѵ�.

Camera::~Camera() {}  // virtual�� �̿��� ���� �Ҹ��� ����