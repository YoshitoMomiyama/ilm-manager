#ifndef	CILMResource_H
#define	CILMResource_H
//-----------------------------------------------------------------------------
#include <vector>
#include <string>

#include <ilm_control.h>

class CIVILayer;
class CIVIScreen;
//-----------------------------------------------------------------------------
class CIVISurface
{
private:
protected:
	bool m_IsConfigured;
	CIVILayer *m_ParentLayer;
	
	t_ilm_uint m_X;
	t_ilm_uint m_Y;
	t_ilm_uint m_Z;
	t_ilm_uint m_Width;
	t_ilm_uint m_Height;
	t_ilm_uint m_Id;
	
public:
	// set method
	void SetParentLayer(CIVILayer* parent){ this->m_ParentLayer = parent; }
	
	// get method
	t_ilm_uint GetSurfaceId() { return this->m_Id; }
	t_ilm_uint GetSurfaceWidth(){ return this->m_Width; }
	t_ilm_uint GetSurfaceHight(){ return this->m_Height; }
	t_ilm_uint GetSurfaceX(){ return this->m_X; }
	t_ilm_uint GetSurfaceY(){ return this->m_Y; }
	t_ilm_uint GetSurfaceZ(){ return this->m_Z; }
	
	CIVILayer* GetParentLayer(){ return this->m_ParentLayer; }

	
	// method
	bool ConfiguredSurface(t_ilm_uint id, t_ilm_uint x, t_ilm_uint y, t_ilm_uint z, t_ilm_uint width, t_ilm_uint height);
	
	CIVISurface();
	CIVISurface(const CIVISurface&) = delete;
	CIVISurface &operator = (const CIVISurface&) = delete;
	
	virtual ~CIVISurface();
};
//-----------------------------------------------------------------------------
class CIVILayer
{
private:
protected:
	std::vector< CIVISurface* > m_Surfaces;
	std::string m_LayerName;
	
	t_ilm_uint m_X;
	t_ilm_uint m_Y;
	t_ilm_uint m_Z;
	t_ilm_uint m_Width;
	t_ilm_uint m_Height;
	t_ilm_uint m_Id;
	
public:
	// set method
	
	// get method
	std::string GetLayerName() { return this->m_LayerName; }
	t_ilm_uint GetLayerId() { return this->m_Id; }
	t_ilm_uint GetLayerWidth(){ return this->m_Width; }
	t_ilm_uint GetLayerHight(){ return this->m_Height; }
	t_ilm_uint GetLayerX(){ return this->m_X; }
	t_ilm_uint GetLayerY(){ return this->m_Y; }
	t_ilm_uint GetLayerZ(){ return this->m_Z; }
	
	CIVISurface* GetSurfaceById(t_ilm_uint id);
	
	//method
	bool CreateLayer(t_ilm_uint x, t_ilm_uint y, t_ilm_uint z, t_ilm_uint width, t_ilm_uint height,
					 t_ilm_uint id, std::string layername);
	
	bool AddSurface(CIVISurface *psurface);
	bool RemoveSurface(CIVISurface *psurface);
	
	CIVILayer();
	CIVILayer(const CIVILayer&) = delete;
	CIVILayer &operator = (const CIVILayer&) = delete;
	
	virtual ~CIVILayer();
};
//-----------------------------------------------------------------------------
class CIVIScreen
{
private:
protected:
	std::vector< CIVILayer* > m_Layers;
	
	std::string m_Name;
	std::string m_ConnectorName;
	t_ilm_uint m_Width;
	t_ilm_uint m_Height;
	t_ilm_uint m_Id;
	
public:
	// set method
	bool AddLayer(CIVILayer *player);
	
	// get method
	std::string GetScreenName() { return this->m_Name; }
	t_ilm_uint GetScreenId() { return this->m_Id; }
	t_ilm_uint GetScreenWidth(){ return this->m_Width; }
	t_ilm_uint GetScreenHight(){ return this->m_Height; }
	
	CIVILayer* GetLayerById(t_ilm_uint id);
	CIVILayer* GetLayerByName(std::string layername);
	
	CIVISurface* GetSurfaceById(t_ilm_uint id);
	
	//method
	void SetParameter(t_ilm_uint id, std::string sname, std::string cname, t_ilm_uint width, t_ilm_uint height);
	
	CIVIScreen();
	CIVIScreen(const CIVIScreen&) = delete;
	CIVIScreen &operator = (const CIVIScreen&) = delete;
	
	virtual ~CIVIScreen();
};
//-----------------------------------------------------------------------------
#endif	//#ifndef	CILMResource_H
