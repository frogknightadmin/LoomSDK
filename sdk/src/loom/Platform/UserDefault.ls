/*
===========================================================================
Loom SDK
Copyright 2011, 2012, 2013 
The Game Engine Company, LLC

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

   http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License. 
===========================================================================
*/

package loom.platform
{
   /**
    * UserDefault acts as a tiny database for local settings. You can save and 
    * get base type values by it. For example, setBoolForKey("played", true) 
    * will add a bool value true into the database. Its key is "played". You
    * can get the value of the key by getBoolForKey("played").
    * 
    * It supports the following base types: bool, int, float, double, string
    */
   public class UserDefault
   {
      /**
      Get bool value by key, if the key doesn't exist, a default value will return.
      You can set the default value, or it is false.
       */
      public function getBoolForKey(key:String, def:Boolean = false):Boolean
      {
      return false;
      }
      
      /**
      Get integer value by key, if the key doesn't exist, a default value will return.
      You can set the default value, or it is 0.
       */
      public function getIntegerForKey(key:String, def:int = 0):int
      {
      return 0;
      }

      /**
      Get float value by key, if the key doesn't exist, a default value will return.
      You can set the default value, or it is 0.0f.
      */
      public function getFloatForKey(key:String, def:Number = 0):Number
      {
       return 0;
      }

      /**
      Get double value by key, if the key doesn't exist, a default value will return.
      You can set the default value, or it is 0.0.
      */
      public function getStringForKey(key:String, def:String = ""):String
      {
      return "";
      }

      /**
      Get double value by key, if the key doesn't exist, a default value will return.
      You can set the default value, or it is 0.0.
      */
      public function getDoubleForKey(key:String, def:Number = 0):Number
      {
      return 0;
      }

      /**
      Set bool value by key.
      */
      public function setBoolForKey(key:String, value:Boolean) {}

      /**
      Set integer value by key.
      */
      public function setIntegerForKey(key:String, value:int) {}

      /**
      Set float value by key.
      */
      public function setFloatForKey(key:String, value:Number) {}

      /**
      Set string value by key.
      */
      public function setStringForKey(key:String, value:String) {}

      /**
      Set double value by key.
      */
      public function setDoubleForKey(key:String, value:Number) {}

      /** 
      Get the singleton instance of UserDefault.
      */
      public static function sharedUserDefault():UserDefault
      {
      return new UserDefault();
      }

      /**
      Removed the shared user defaults from the filesystem
      */
      public static function purgeSharedUserDefault()
      {}
   }
}