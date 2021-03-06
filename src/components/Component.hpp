//
// Created by Krisu on 2020/2/29.
//

#ifndef RENDER_ENGINE_COMPONENT_HPP
#define RENDER_ENGINE_COMPONENT_HPP

/*
 * In a typical rendering application:
 *
 *
 * All Components' BeforeRenderLoop() called...
 *
 * while renderLoop not end {
 *
 *      for object in objectList {
 *          for component in object {
 *              component.BeforeRenderPass
 *          }
 *          render(object)
 *          for component in object {
 *              component.AfterRenderPass
 *          }
 *      }
 *
 * }
 */

class GameObject;

class Component {
public:
    /*  will be called before render loop for all components */
    virtual void BeforeRenderLoop() { }

    /* will be called in the render loop, before each frame rendererd */
    virtual void BeforeRenderPass() { }

    /* will be called in the render loop, after each frame rendererd */
    virtual void AfterRenderPass() { }

    /* get the owner of the Component */
    GameObject& GetGameObject() { return *owner; }

private:
    /* owner of this Component */
    GameObject *owner = nullptr;
    
    friend class GameObject;
};


#endif //RENDER_ENGINE_COMPONENT_HPP
