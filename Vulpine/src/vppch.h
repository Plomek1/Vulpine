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
#include "Vulpine/Events/ApplicationEvent.h"
#include "Vulpine/Events/KeyEvent.h"
#include "Vulpine/Events/MouseEvent.h"

#ifdef VP_PLATFORM_WINDOWS
	#include <Windows.h>
#endif