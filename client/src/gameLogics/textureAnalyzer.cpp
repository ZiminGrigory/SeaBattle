#include "textureAnalyzer.h"

TextureAnalyzer::TextureAnalyzer()
{
}

Textures shipTexture(int i, int shipSize, bool orientation)
{
	switch (shipSize) {
	case 2:{
		if (orientation) { //horizontally
			if (i == 1) {
				return SHIP_BOW_HORIZONTAL;
			}else {
				return SHIP_POOP_HORIZONTAL;
			}
		} else {
			if (i == 1) {
				return SHIP_BOW_VERTICAL;
			}else {
				return SHIP_POOP_VERTICAL;
			}
		}
	}
	break;
	case 3:{
		if (orientation) { //horizontally
			switch (i) {
			case 1:
				return SHIP_BOW_HORIZONTAL;
				break;
			case 2:
				return SHIP_DECK_HORIZONTAL;
				break;
			case 3:
				return SHIP_POOP_HORIZONTAL;
				break;
			}
		} else {
			switch (i) {
			case 1:
				return SHIP_BOW_VERTICAL;
				break;
			case 2:
				return SHIP_DECK_VERTICAL;
				break;
			case 3:
				return SHIP_POOP_VERTICAL;
				break;
			}
		}
	}
	break;
	case 4:{
		if (orientation) { //horizontally
			switch (i) {
			case 1:
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
				break;
			}
		} else {
			switch (i) {
			case 1:
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
				break;
			}
		}
	}
	break;
	}
	return SHIP_SINGLE;
}

Textures shipDamagedTexture(int i, int shipSize, bool orientation)
{
	switch (shipSize) {
	case 2:{
		if (orientation) { //horizontally
			if (i == 1) {
				return SHIP_BOW_HORIZONTAL_BURN;
			}else {
				return SHIP_POOP_HORIZONTAL_BURN;
			}
		} else {
			if (i == 1) {
				return SHIP_BOW_VERTICAL_BURN;
			}else {
				return SHIP_POOP_VERTICAL_BURN;
			}
		}
	}
	break;
	case 3:{
		if (orientation) { //horizontally
			switch (i) {
			case 1:
				return SHIP_BOW_HORIZONTAL_BURN;
				break;
			case 2:
				return SHIP_DECK_HORIZONTAL_BURN;
				break;
			case 3:
				return SHIP_POOP_HORIZONTAL_BURN;
				break;
			}
		} else {
			switch (i) {
			case 1:
				return SHIP_BOW_VERTICAL_BURN;
				break;
			case 2:
				return SHIP_DECK_VERTICAL_BURN;
				break;
			case 3:
				return SHIP_POOP_VERTICAL_BURN;
				break;
			}
		}
	}
	break;
	case 4:{
		if (orientation) { //horizontally
			switch (i) {
			case 1:
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
				break;
			}
		} else {
			switch (i) {
			case 1:
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
				break;
			}
		}
	}
	break;
	}
	return SHIP_SINGLE_BURN;
}
