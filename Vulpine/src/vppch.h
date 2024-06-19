#pragma once


#include <iostream>
#include <functional>
#include <memory>
#include <utility>
#include <algorithm>


#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#include "Vulpine/Log.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"

#ifdef VP_PLATFORM_WINDOWS
	#include <Windows.h>
#endif