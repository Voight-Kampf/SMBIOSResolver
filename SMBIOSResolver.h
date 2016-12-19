/* --- SMBIOS Resolver kext --- SMBIOSResolver.h
The main purpose is to fill in information that is missing or erronoeus in a common x86 PC
*/

/* (C) 2008 Superhai
Thanks to Kabyl for some foundation and fsb calculation routine */

/* 2016 Goodwin */

#define K8_FIDVID_STATUS	0xC0010042
#define K10_COFVID_STATUS	0xC0010071

#define cpuid_family 6
#define cpuid_model  94
#define cpuid_vendor CPUID_VID_INTEL
#define cpuid_extfamily 3

class SMBIOSResolver : public IOService
	{
		OSDeclareDefaultStructors( SMBIOSResolver )

	protected:
		enum { kMemDataSize = 64 };
		OSData *	memManufData;
		OSData *	memSerialData;
		OSData *	memPartData;
		OSData *	memSpeedData;
		UInt64		calcCPU( UInt64 fsb_frequency_hz );
	public:
		virtual IOService *	probe(IOService * provider, SInt32 * score);
		virtual bool		start(IOService * provider);
		virtual void		stop(IOService * provider);
		virtual void		free(void);
	};

