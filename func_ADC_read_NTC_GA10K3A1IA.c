//Ler ADC
float read_temp(uint16_t adc_value) {
	//divisor de tensão - R1 = 10k
	//GA10K3A1IA
	//constantes
	static const float VSS 3.3 		 	 // 3.3v
	static const uint8_t GND 0   			 // 0v
	static const uint16_t ADC_RES 4095.0  	 // ADC resolution
	static const uint16_t NTC_BETA 3976.0      // Beta
	static const uint16_t NTC_R0 9700.0          // Resistencia @ 25°C
	static const uint8_t NTC_T0 298.15        // 25°C em Kelvin

    float voltage_out = (adc_value / ADC_RES) * VSS;
    float r_ntc = (voltage_out * 10000) / (VSS - voltage_out);
    float temp = 1.0 / ((1.0 / NTC_T0) + (1.0 / NTC_BETA) * log(r_ntc / NTC_R0));
    return temp - 273.15;  // Celsius
}
