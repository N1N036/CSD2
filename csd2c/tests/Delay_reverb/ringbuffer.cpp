#include "ringbuffer.h"
#include <experimental/iterator>

//constructor and destructor
ringBuffer::ringBuffer(int length)
{
  this->length = length;
  //ringBuf = std::vector<double> ringBuf(length, 0.0);
  ringBuf.reserve(length);
  for (int i = 0; i <= length ; i++)
  {
    ringBuf.push_back(0.0);
  }
}

ringBuffer::~ringBuffer(){}

void ringBuffer::push(double dInput)
{

  ringBuf[iRingBuf] = dInput;
  iRingBuf++;
  iRingBuf = iRingBuf % length;
}

double ringBuffer::getSample(int iDelay)
{
  return ringBuf[(iRingBuf + length - iDelay - 1) % length];
}

double ringBuffer::getSamples(int iDelays[],float fVolumes[])
{
  out = 0.0;
  int size = (*(&iDelays + 1) - iDelays - 1);
  for (int i = 0; i <= size ; i++)
  {
    out += fVolumes[i]*ringBuf[(iRingBuf + length - iDelays[i] % length) % length];
    //out = out % (length);
    //std::cout<<fVolumes[i]<<std::endl;
  }
  //std::cout<<out<<std::endl;
  return out;
}
