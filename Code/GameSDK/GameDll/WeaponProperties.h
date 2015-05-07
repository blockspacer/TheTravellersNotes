/****************************************************************************************************
* File: WeaponProperties.h
* Description: � ������ ����� ��������� ����� �������� ������
* Created by: Andrew Medvedev
* Date: 29.09.2014
* Edda Studio
****************************************************************************************************/

#pragma once

//��������:
//� ������ ������������ ��������� ��������� ���� ������.
//������� ������ ����� ����� ������������, ������� ������ �� ��������.
enum EWeaponType
{
	//������� ���� ������
	e_WeaponTypeSword,
	e_WeaponTypeBow,
	e_WeaponTypeAxe,

	//������������
	e_WeaponSubtypeShort = 1 << 4,
	e_WeaponSubtypeLong  = 1 << 5,
};