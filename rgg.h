#ifndef RGG_H_
#define RGG_H_

/*
	const unsigned int	signature1 = 0x00ff00ff;
	const unsigned int	signature2 = 0x01fc01fe;
	const unsigned int	signature3 = 0x01f001f8;
	const unsigned int	signature4 = 0x56aa55aa;
*/

#pragma pack(push, 1)

// 32
struct Signature {
	unsigned int	signature1 ;
	unsigned int	signature2 ;
	unsigned int	signature3 ;
	unsigned int	signature4 ;
	unsigned char	headCode;
	unsigned char	headVersion;

	unsigned char	reserved[14];
};

// 128
struct Flight {
	unsigned char	headVersion;
	int64_t			armTime;
	int64_t			gpsTime;
	unsigned int	missionNumber;
	unsigned int	flightNumber;
	unsigned int	phaseNumber;
	unsigned int	fileNumber;
	char			flightCountry[16];		// CP-1251 \0
	char			flightTerritory[16];	// CP-1251 \0

	unsigned char	reserved[63];
};

// 64
struct Locator {
	unsigned char	headVersion;
	unsigned char	band;
	unsigned char	channel;
	unsigned char	mode;

	unsigned char	reserved[60];
};

// 64
struct Receiver {
	unsigned char	headVersion;
	unsigned char	polarization;
	float			bandWidth;
	float			kFadingUatt;
	unsigned char	fVaru;

	unsigned char	reserved[53];
};

// 64
struct Transmitter {
	unsigned char	headVersion;
	float			freqCarrier;
	float			freqDeviation;
	float			lenthImpulse;
	float			dopplerShift;

	unsigned char	reserved[47];
};

// 64
struct Synchronizer {
	unsigned char	headVersion;
	unsigned char	observeMode;
	unsigned char	observeSide;
	unsigned char	polarization;
	float			minRange;
	unsigned char	impFreqDivisor;
//	unsigned char	radio;
	char			signRangeLfm;
//	unsigned char	throughChannel;
//	unsigned char	aerialEquiv;
//	unsigned char	noiseGen;
//	unsigned char	sizingSignal;
	unsigned char	genIntExt;
	unsigned char	genFreqDivisor;
	char			signAzLfm;
	float           discreteAz;

	unsigned char	reserved[47];
};

// 64
struct Generator {
	unsigned char	headVersion;
	unsigned char	prdu;
	unsigned char	vn;
	unsigned char	radio;
	unsigned char	equiv;

	unsigned char	reserved[59];
};

// 64
struct Cooling {
	unsigned char	headVersion;
	unsigned char	pump;
	unsigned char	fan1;
	unsigned char	fan2;
	unsigned char	PT;

	unsigned char	reserved[59];
};

// 64
struct Aerial {
	unsigned char	headVersion;
	float			degAperture;

	unsigned char	reserved[59];
};

// 128
struct Adc {
	unsigned char	headVersion;
	float			freqAdc;
	unsigned char	freqAdcDivisor;
	unsigned int	lenthStringRgg;
	unsigned int	adcLatency;
	unsigned char	freqGen;
	unsigned int	genExtFreq;
	unsigned int	genExtFreqDivisor;
	char			firmwareName[64];	// ASCII \0
	unsigned char	dataFormat;

	unsigned char	reserved[40];
};

// 64
struct Format {
	unsigned char	typeData;
	unsigned char	typeSamples;
	unsigned char	orderData;
	unsigned int	cntSamples;
    unsigned char 	lchm;
	unsigned char	reserved[56];
};

// 800
typedef struct RggHeader {
	struct Signature	signature;
	struct Flight		flight;
	struct Locator		locator;
	struct Receiver		receiver;
	struct Transmitter	transmitter;
	struct Synchronizer	synchronizer;
	struct Generator	generator;
	struct Cooling		cooling;
	struct Aerial		aerial;
	struct Adc			adc;
	struct Format		format;
} RggHeader;

// 768
struct Navigation {
	unsigned char	headVersion;
	int64_t			timeArm;
	int64_t			timeGps;
	unsigned int	strNumber;

	bool			dataSnp;
	double			altitudeSnp;
	double			angleSnp;
	double			latitudeSnp;
	double			latitudePrecSnp;
	double			longitudePrecSnp;
	double			longitudeSnp;
	unsigned int	latencySnp;
	double			vHSnp;
	double			vNSnp;
	double			vESnp;
	double			horizontSko;

	bool			dataIns;
	double			latitudeIns;
	double			longitudeIns;
	double			vNIns;
	double			vEIns;
	double			vIns;
	double			courseIns;
	double			angleIns;
	double			gyroIns;
	double			driftIns;
	double			bankIns;
	double			tangageIns;

	double			accelerationX1Ins;
	double			accelerationY1Ins;
	double			accelerationZ1Ins;
	double			accelerationX2Ins;
	double			accelerationY2Ins;
	double			accelerationZ2Ins;
	double			accelerationX3Ins;
	double			accelerationY3Ins;
	double			accelerationZ3Ins;
	double			accelerationX4Ins;
	double			accelerationY4Ins;
	double			accelerationZ4Ins;

	bool			dataInsSns;
	double			latitudeInsSns;
	double			longitudeInsSns;
	double			altitudeInsSns;
	double			vNInsSns;
	double			vEInsSns;
	double			courseInsSns;

	unsigned char	reserved[428];
};

// 32
struct CtrlReceiver {
	unsigned char	headVersion;
	unsigned char	ip;

	unsigned char	reserved[30];
};

// 32
struct CtrlTransmitter {
	unsigned char	headVersion;
	unsigned char	umKip;
	unsigned char	umOutP;
	unsigned char	lfmKimp;
	unsigned char	kReflection;
	unsigned char	fchsKip;
	unsigned char	kgk;
	unsigned char	pchKf;
	unsigned char	lfmKf;
	unsigned char	kFg;
	unsigned char	kFchs;

	unsigned char	reserved[21];
};

// 32
struct CtrlSynchronizer {
	unsigned char	headVersion;
	unsigned char	afu;
	unsigned char	umThreshold;
	unsigned char	Izl;
	unsigned char	SkvozSig;
	unsigned char	EkvivAnt;
	unsigned char	GenShum;
	unsigned char	PilotSig;
	unsigned char	SecMet;
	unsigned char	Bort;
	unsigned char	Polyar;
	unsigned char	SignLcmDn;
	unsigned char	reserved[20];
};

// 32
struct CtrlGenerator {
	unsigned char	headVersion;
	unsigned char	prdu;
	unsigned char	vn;
	unsigned char	ksv;
	unsigned char	pum;
	unsigned char	ipPum;
	unsigned char	mip;
	unsigned char	mk;
	unsigned char	pin;
	unsigned char	prduStrobe;
	unsigned char	pumStrobe;
	unsigned char	ctrlOutP;

	unsigned char	reserved[20];
};

// 32
struct CtrlCooling {
	unsigned char	headVersion;
	unsigned char	dd1;
	unsigned char	dd2;
	unsigned char	spd;

	unsigned char	reserved[28];
};

// 32
struct CtrlAerial {
	unsigned char	headVersion;

	unsigned char	reserved[31];
};

// 32
struct CtrlAdc {
	unsigned char	headVersion;

	unsigned char	reserved[31];
};

// 1024
typedef struct RggStrHeader {
	struct Signature		signature;
	struct Navigation		navigation;
	struct CtrlReceiver		ctrlReceiver;
	struct CtrlTransmitter	ctrlTransmitter;
	struct CtrlSynchronizer	ctrlSynchronizer;
	struct CtrlGenerator	ctrlGenerator;
	struct CtrlCooling		ctrlCooling;
	struct CtrlAerial		ctrlAerial;
	struct CtrlAdc			ctrlAdc;
} RggStrHeader;

#endif
