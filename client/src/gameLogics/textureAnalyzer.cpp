#include "textureAnalyzer.h"

TextureAnalyzer::TextureAnalyzer()
{
}

<<<<<<< HEAD
Textures TextureAnalyzer::shipDamagedTexture(int i, int shipSize, bool orientation)
=======
Textures TextureAnalyzer::shipTexture(int i, int shipSize, bool orientation)
>>>>>>> 080d807b3dc3e72f0e434748d19637f44410042c
{
	switch (shipSize) {
	case 2:{
		if (orientation) { //horizontally
			if (i == 1) {
<<<<<<< HEAD
				return SHIP_BOW_HORIZONTAL_BURN;
			}else {
				return SHIP_POOP_HORIZONTAL_BURN;
			}
		} else {
			if (i == 1) {
				return SHIP_BOW_VERTICAL_BURN;
			}else {
				return SHIP_POOP_VERTICAL_BURN;
=======
				return SHIP_BOW_HORIZONTAL;
			}else {
				return SHIP_POOP_HORIZONTAL;
			}
		} else {
			if (i == 1) {
				return SHIP_BOW_VERTICAL;
			}else {
				return SHIP_POOP_VERTICAL;
>>>>>>> 080d807b3dc3e72f0e434748d19637f44410042c
			}
		}
	}
	break;
	case 3:{
		if (orientation) { //horizontally
			switch (i) {
			case 1:
<<<<<<< HEAD
				return SHIP_BOW_HORIZONTAL_BURN;
				break;
			case 2:
				return SHIP_DECK_HORIZONTAL_BURN;
				break;
			case 3:
				return SHIP_POOP_HORIZONTAL_BURN;
=======
				return SHIP_BOW_HORIZONTAL;
				break;
			case 2:
				return SHIP_DECK_HORIZONTAL;
				break;
			case 3:
				return SHIP_POOP_HORIZONTAL;
>>>>>>> 080d807b3dc3e72f0e434748d19637f44410042c
				break;
			}
		} else {
			switch (i) {
			case 1:
<<<<<<< HEAD
				return SHIP_BOW_VERTICAL_BURN;
				break;
			case 2:
				return SHIP_DECK_VERTICAL_BURN;
				break;
			case 3:
				return SHIP_POOP_VERTICAL_BURN;
=======
				return SHIP_BOW_VERTICAL;
				break;
			case 2:
				return SHIP_DECK_VERTICAL;
				break;
			case 3:
				return SHIP_POOP_VERTICAL;
>>>>>>> 080d807b3dc3e72f0e434748d19637f44410042c
				break;
			}
		}
	}
	break;
	case 4:{
		if (orientation) { //horizontally
			switch (i) {
			case 1:
<<<<<<< HEAD
				return SHIP_BOW_HORIZONTAL_BURN;
				break;
			case 2:
				return SHIP_DECK_HORIZONTAL_BURN;
				break;
			case 3:
				return SHIP_DECK_HORIZONTAL_BURN;
				break;
			case 4:
				return SHIP_POOP_HORIZONTAL_BURN;
=======
				return SHIP_BOW_HORIZONTAL;
				break;
			case 2:
				return SHIP_DECK_HORIZONTAL;
				break;
			case 3:
				return SHIP_DECK_HORIZONTAL;
				break;
			case 4:
				return SHIP_POOP_HORIZONTAL;
>>>>>>> 080d807b3dc3e72f0e434748d19637f44410042c
				break;
			}
		} else {
			switch (i) {
			case 1:
<<<<<<< HEAD
				return SHIP_BOW_VERTICAL_BURN;
				break;
			case 2:
				return SHIP_DECK_VERTICAL_BURN;
				break;
			case 3:
				return SHIP_DECK_VERTICAL_BURN;
				break;
			case 4:
				return SHIP_POOP_VERTICAL_BURN;
=======
				return SHIP_BOW_VERTICAL;
				break;
			case 2:
				return SHIP_DECK_VERTICAL;
				break;
			case 3:
				return SHIP_DECK_VERTICAL;
				break;
			case 4:
				return SHIP_POOP_VERTICAL;
>>>>>>> 080d807b3dc3e72f0e434748d19637f44410042c
				break;
			}
		}
	}
	break;
	}
<<<<<<< HEAD
	return SHIP_SINGLE_BURN;
}


Textures TextureAnalyzer::shipTexture(int i, int shipSize, bool orientation)
=======
	return SHIP_SINGLE;
}

Textures TextureAnalyzer::shipDamagedTexture(int i, int shipSize, bool orientation)
>>>>>>> 080d807b3dc3e72f0e434748d19637f44410042c
{
	switch (shipSize) {
	case 2:{
		if (orientation) { //horizontally
			if (i == 1) {
<<<<<<< HEAD
				return SHIP_BOW_HORIZONTAL;
			}else {
				return SHIP_POOP_HORIZONTAL;
			}
		} else {
			if (i == 1) {
				return SHIP_BOW_VERTICAL;
			}else {
				return SHIP_POOP_VERTICAL;
=======
				return SHIP_BOW_HORIZONTAL_BURN;
			}else {
				return SHIP_POOP_HORIZONTAL_BURN;
			}
		} else {
			if (i == 1) {
				return SHIP_BOW_VERTICAL_BURN;
			}else {
				return SHIP_POOP_VERTICAL_BURN;
>>>>>>> 080d807b3dc3e72f0e434748d19637f44410042c
			}
		}
	}
	break;
	case 3:{
		if (orientation) { //horizontally
			switch (i) {
			case 1:
<<<<<<< HEAD
				return SHIP_BOW_HORIZONTAL;
				break;
			case 2:
				return SHIP_DECK_HORIZONTAL;
				break;
			case 3:
				return SHIP_POOP_HORIZONTAL;
=======
				return SHIP_BOW_HORIZONTAL_BURN;
				break;
			case 2:
				return SHIP_DECK_HORIZONTAL_BURN;
				break;
			case 3:
				return SHIP_POOP_HORIZONTAL_BURN;
>>>>>>> 080d807b3dc3e72f0e434748d19637f44410042c
				break;
			}
		} else {
			switch (i) {
			case 1:
<<<<<<< HEAD
				return SHIP_BOW_VERTICAL;
				break;
			case 2:
				return SHIP_DECK_VERTICAL;
				break;
			case 3:
				return SHIP_POOP_VERTICAL;
=======
				return SHIP_BOW_VERTICAL_BURN;
				break;
			case 2:
				return SHIP_DECK_VERTICAL_BURN;
				break;
			case 3:
				return SHIP_POOP_VERTICAL_BURN;
>>>>>>> 080d807b3dc3e72f0e434748d19637f44410042c
				break;
			}
		}
	}
	break;
	case 4:{
		if (orientation) { //horizontally
			switch (i) {
			case 1:
<<<<<<< HEAD
				return SHIP_BOW_HORIZONTAL;
				break;
			case 2:
				return SHIP_DECK_HORIZONTAL;
				break;
			case 3:
				return SHIP_DECK_HORIZONTAL;
				break;
			case 4:
				return SHIP_POOP_HORIZONTAL;
=======
				return SHIP_BOW_HORIZONTAL_BURN;
				break;
			case 2:
				return SHIP_DECK_HORIZONTAL_BURN;
				break;
			case 3:
				return SHIP_DECK_HORIZONTAL_BURN;
				break;
			case 4:
				return SHIP_POOP_HORIZONTAL_BURN;
>>>>>>> 080d807b3dc3e72f0e434748d19637f44410042c
				break;
			}
		} else {
			switch (i) {
			case 1:
<<<<<<< HEAD
				return SHIP_BOW_VERTICAL;
				break;
			case 2:
				return SHIP_DECK_VERTICAL;
				break;
			case 3:
				return SHIP_DECK_VERTICAL;
				break;
			case 4:
				return SHIP_POOP_VERTICAL;
=======
				return SHIP_BOW_VERTICAL_BURN;
				break;
			case 2:
				return SHIP_DECK_VERTICAL_BURN;
				break;
			case 3:
				return SHIP_DECK_VERTICAL_BURN;
				break;
			case 4:
				return SHIP_POOP_VERTICAL_BURN;
>>>>>>> 080d807b3dc3e72f0e434748d19637f44410042c
				break;
			}
		}
	}
	break;
	}
<<<<<<< HEAD
	return SHIP_SINGLE;
=======
	return SHIP_SINGLE_BURN;
>>>>>>> 080d807b3dc3e72f0e434748d19637f44410042c
}
