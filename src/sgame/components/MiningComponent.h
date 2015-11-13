#ifndef MINING_COMPONENT_H_
#define MINING_COMPONENT_H_

#include "../backend/CBSEBackend.h"
#include "../backend/CBSEComponents.h"

class MiningComponent: public MiningComponentBase {
	public:
		// ///////////////////// //
		// Autogenerated Members //
		// ///////////////////// //

		/**
		 * @brief Default constructor of the MiningComponent.
		 * @param entity The entity that owns the component instance.
		 * @param r_ResourceStorageComponent A ResourceStorageComponent instance that this component depends on.
		 * @param r_ThinkingComponent A ThinkingComponent instance that this component depends on.
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		MiningComponent(Entity& entity, ResourceStorageComponent& r_ResourceStorageComponent, ThinkingComponent& r_ThinkingComponent);

		/**
		 * @brief Handle the PrepareNetCode message.
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		void HandlePrepareNetCode();

		/**
		 * @brief Handle the Die message.
		 * @param killer
		 * @param meansOfDeath
		 * @note This method is an interface for autogenerated code, do not modify its signature.
		 */
		void HandleDie(gentity_t* killer, meansOfDeath_t meansOfDeath);

		// ///////////////////// //

		/**
		 * @brief Calculates modifier for the efficiency of one RGS when another one interfers at
		 *        given distance.
		 */
		static float InterferenceMod(float distance);

		/**
		 * @brief Adjust the mining  efficiency.
		 * @note This doesn't need to be called for regular mining entities but there is a hack that
		 *       needs this to be public.
		 */
		void CalculateEfficiency();

		float Efficiency() { return efficiency; }
		float MineRate() { return efficiency * level.mineRate; }

	private:
		float efficiency;

		/**
		 * @brief Whether the component was active during the last thinker execution.
		 */
		bool lastThinkActive;

		/**
		 * @return Whether this component is currently mining (and interfering with other miners).
		 */
		bool Active();

		/**
		 * @brief Adjust the rate of all other mining structures in range.
		 */
		void InformNeighbors();

		void Think(int timeDelta);
};

#endif // MINING_COMPONENT_H_