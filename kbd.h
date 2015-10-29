//numbers
case GLFW_KEY_0: if(shiftStatus) vmKBDEvent(41); else vmKBDEvent(key); break;
case GLFW_KEY_1: if(shiftStatus) vmKBDEvent(33); else vmKBDEvent(key); break;
case GLFW_KEY_2: if(shiftStatus) vmKBDEvent(64); else vmKBDEvent(key); break;
case GLFW_KEY_3: if(shiftStatus) vmKBDEvent(35); else vmKBDEvent(key); break;
case GLFW_KEY_4: if(shiftStatus) vmKBDEvent(36); else vmKBDEvent(key); break;
case GLFW_KEY_5: if(shiftStatus) vmKBDEvent(37); else vmKBDEvent(key); break;
case GLFW_KEY_6: if(shiftStatus) vmKBDEvent(94); else vmKBDEvent(key); break;
case GLFW_KEY_7: if(shiftStatus) vmKBDEvent(38); else vmKBDEvent(key); break;
case GLFW_KEY_8: if(shiftStatus) vmKBDEvent(42); else vmKBDEvent(key); break;
case GLFW_KEY_9: if(shiftStatus) vmKBDEvent(40); else vmKBDEvent(key); break;

//alpha
case GLFW_KEY_A:
case GLFW_KEY_B:	
case GLFW_KEY_C:
case GLFW_KEY_D:
case GLFW_KEY_E:
case GLFW_KEY_F:
case GLFW_KEY_G:
case GLFW_KEY_H:
case GLFW_KEY_I:
case GLFW_KEY_J:
case GLFW_KEY_K:
case GLFW_KEY_L:
case GLFW_KEY_M:
case GLFW_KEY_N:
case GLFW_KEY_O:
case GLFW_KEY_P:
case GLFW_KEY_Q:
case GLFW_KEY_R:
case GLFW_KEY_S:
case GLFW_KEY_T:
case GLFW_KEY_U:
case GLFW_KEY_V:
case GLFW_KEY_W:
case GLFW_KEY_X:
case GLFW_KEY_Y:
case GLFW_KEY_Z:
	if(shiftStatus) vmKBDEvent(key); else vmKBDEvent(key+32); break;

//symbols
case GLFW_KEY_COMMA: if(shiftStatus) vmKBDEvent(60); else vmKBDEvent(key); break;
case GLFW_KEY_PERIOD: if(shiftStatus) vmKBDEvent(62); else vmKBDEvent(key); break;
case GLFW_KEY_SLASH: if(shiftStatus) vmKBDEvent(63); else vmKBDEvent(key); break;
case GLFW_KEY_SEMICOLON: if(shiftStatus) vmKBDEvent(58); else vmKBDEvent(key); break;
case GLFW_KEY_APOSTROPHE: if(shiftStatus) vmKBDEvent(34); else vmKBDEvent(key); break;
case GLFW_KEY_LEFT_BRACKET: if(shiftStatus) vmKBDEvent(123); else vmKBDEvent(key); break;
case GLFW_KEY_RIGHT_BRACKET: if(shiftStatus) vmKBDEvent(125); else vmKBDEvent(key); break;
case GLFW_KEY_MINUS: if(shiftStatus) vmKBDEvent(95); else vmKBDEvent(key); break;
case GLFW_KEY_EQUAL: if(shiftStatus) vmKBDEvent(43); else vmKBDEvent(key); break;
case GLFW_KEY_GRAVE_ACCENT: if(shiftStatus) vmKBDEvent(126); else vmKBDEvent(key); break;
case GLFW_KEY_BACKSLASH: if(shiftStatus) vmKBDEvent(124); else vmKBDEvent(key); break;

//space
case GLFW_KEY_SPACE: vmKBDEvent(key); break;

//special keys
case GLFW_KEY_ENTER: vmKBDEvent(128); break;
case GLFW_KEY_BACKSPACE: vmKBDEvent(129); break;
case GLFW_KEY_LEFT: vmKBDEvent(130); break;
case GLFW_KEY_UP: vmKBDEvent(131); break;
case GLFW_KEY_RIGHT: vmKBDEvent(132); break;
case GLFW_KEY_DOWN: vmKBDEvent(133); break;
case GLFW_KEY_HOME: vmKBDEvent(134); break;
case GLFW_KEY_END: vmKBDEvent(135); break;
case GLFW_KEY_PAGE_UP: vmKBDEvent(136); break;
case GLFW_KEY_PAGE_DOWN: vmKBDEvent(137); break;
case GLFW_KEY_INSERT: vmKBDEvent(138); break;
case GLFW_KEY_DELETE: vmKBDEvent(139); break;
case GLFW_KEY_ESCAPE: vmKBDEvent(140); break;

//F keys
case GLFW_KEY_F1: vmKBDEvent(141); break;
case GLFW_KEY_F2: vmKBDEvent(142); break;
case GLFW_KEY_F3: vmKBDEvent(143); break;
case GLFW_KEY_F4: vmKBDEvent(144); break;
case GLFW_KEY_F5: vmKBDEvent(145); break;
case GLFW_KEY_F6: vmKBDEvent(146); break;
case GLFW_KEY_F7: vmKBDEvent(147); break;
case GLFW_KEY_F8: vmKBDEvent(148); break;
case GLFW_KEY_F9: vmKBDEvent(149); break;
case GLFW_KEY_F10: vmKBDEvent(150); break;
case GLFW_KEY_F11: vmKBDEvent(151); break;
case GLFW_KEY_F12: vmKBDEvent(152); break;

//unknown key
default: vmKBDEvent(0); break;
