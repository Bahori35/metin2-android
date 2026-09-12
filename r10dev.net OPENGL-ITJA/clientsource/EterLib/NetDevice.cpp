#include "StdAfx.h"
#include "NetDevice.h"

CNetworkDevice::CNetworkDevice()
{
	Initialize();
}

CNetworkDevice::~CNetworkDevice()
{
	Destroy();
}

void CNetworkDevice::Initialize()
{
	m_isWSA = false;
}

void CNetworkDevice::Destroy()
{
	if (m_isWSA)
	{
#ifndef __ANDROID__
		WSACleanup();
#endif
		m_isWSA = false;
	}
}

bool CNetworkDevice::Create()
{
	Destroy();

	Initialize();

#ifndef __ANDROID__
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(1, 1), &wsaData) != 0)
		return false;
#endif

	m_isWSA = true;

	return true;
}