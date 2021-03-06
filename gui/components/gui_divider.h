/*
 * Copyright (c) 2001 Hansj�rg Malthaner
 * Written (w) 2001 Markus Weber
 *
 * This file is part of the Simutrans project under the artistic licence.
 * (see licence.txt)
 */

#ifndef gui_components_gui_divider_h
#define gui_components_gui_divider_h

#include "gui_komponente.h"
#include "../../simgraph.h"
#include "../../simcolor.h"


/**
 * Eine einfache Trennlinie
 *
 * @date 30-Oct-01
 * @author Markus Weber
 */
class gui_divider_t : public gui_komponente_t
{
public:

	/**
	 * Pre-defined divider line styles
	 * Values > 2 creates an inset bevel
	 * @author Max Kielland
	*/
	enum {
		DIVIDER_RAISED  = 0, //@< 2px divider raised etched
		DIVIDER_LINE    = 1, //@< 1px divider line (SYS_COL_HIGHLIGHT)
		DIVIDER_LOWERED = 2  //@< 2px divider lowered etchedkOut  = 0,  //@< 2px divider out
	};

	gui_divider_t(void) { groesse.y = DIVIDER_LOWERED; }

	void init( koord xy, KOORD_VAL width, KOORD_VAL height = DIVIDER_LOWERED ) {
		set_pos( xy );
		set_groesse( koord( width, height ) );
	};

	/**
	* Vorzugsweise sollte diese Methode zum Setzen der Gr��e benutzt werden,
	* obwohl groesse public ist.
	* @author Hj. Malthaner
	*/
	void set_width(KOORD_VAL width) {

		set_groesse(koord(width,groesse.y));
	}

	virtual koord get_groesse() const {

		return koord(groesse.x,max(groesse.y,D_DIVIDER_HEIGHT));
	}

	/**
	 * Zeichnet die Komponente
	 * @author Markus Weber
	 */
	void zeichnen(koord offset) {

		KOORD_VAL h = (groesse.y == DIVIDER_LINE) ? 1 : ( (groesse.y == DIVIDER_LOWERED) ? 2 : groesse.y );
		KOORD_VAL align_y = D_GET_CENTER_ALIGN_OFFSET(h,D_DIVIDER_HEIGHT);

		display_ddd_box_clip(
			pos.x + offset.x,
			pos.y + offset.y + align_y,
			groesse.x,
			groesse.y,
			SYS_COL_SHADOW,
			SYS_COL_HIGHLIGHT
		);
	}

};

#endif
