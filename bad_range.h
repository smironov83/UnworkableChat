//������������ ���������� ���������� ������ �� ������� �������
//�������������� ������� ChatBot'� � ������ ��������� ���������� ����
//��� ���������������� ��������� ��������� ��������� ��������� �����.
//���������� � ������������ �����.

#pragma once
#include <exception>

struct bad_range :public std::exception
{
	virtual const char* what() const noexcept override
	{
		return "ERROR:!!!����� �� ������� ���������� ������ ChatBot'�!!!";
	}
};