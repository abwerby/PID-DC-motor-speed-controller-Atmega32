/*
 * std_macros.h
 *
 * Created: 30/08/2019 01:09:48 م
 *  Author: DR.LAP
 */ 


#ifndef STD_MACROS_H_
#define STD_MACROS_H_

#define SET_BIT(reg,bit) (reg |=(1<<bit)) //PORTA |=(1<<2)
#define CLR_BIT(reg,bit) (reg &=~(1<<bit)) //PORTA &=~(1<<0)
#define GET_BIT(reg,bit) ((reg &(1<<bit))>>bit) //((PINA &(1<<3))>>3)??
#define TOG_BIT (reg,bit) (reg ^=(1<<bit)) // PORTA ^=(1<<0)
#define ROR     (reg,bit)  (reg=((reg>>num)|(reg<<num %8)))


#endif /* STD_MACROS_H_ */