#pragma once
#include "idyll.hpp"

#include "resource/resource.hpp"

TEST_ENV(resource_manager)

    TEST_SECTION("ResourceManager")
        struct Pos2D 
        {
            int x, y;

            static std::vector<uint8_t> create_data(int x, int y) 
            {
                std::vector<uint8_t> data;
                data.resize(sizeof(x) + sizeof(y));
                std::memcpy(data.data(), &x, sizeof(x));
                std::memcpy(data.data() + sizeof(x), &y, sizeof(y));

                return data;
            }
        };

        class Pos2DManager : public torii::ResourceManager<Pos2D> 
        { 
        public:
            virtual Pos2D* load( const std::string& id ) override
            { 
                auto itRes = m_resources.emplace(id, new Pos2D()).first;
                Pos2D* pRes = (*itRes).second;
                pRes->x = 0;
                pRes->y = 0;
                return pRes;
            }

            virtual Pos2D* load( const std::string& id, const std::vector<uint8_t>& data ) override
            {
                auto itRes = m_resources.emplace(id, new Pos2D()).first;
                Pos2D* pRes = (*itRes).second;

                std::memcpy(&pRes->x, data.data(), sizeof(int));
                std::memcpy(&pRes->y, data.data() + sizeof(int), sizeof(int));

                return pRes;
            }
        };

        TEST("Basic")
            Pos2DManager posMngr;
            Pos2D* position = posMngr.load("FirstPos", Pos2D::create_data(1337, 420));
            Pos2D* position2 = posMngr.get("FirstPos");
            Pos2D* position3 = posMngr.get("SecondPos");
            
            IDYLL_ASSERT(position->x == 1337);
            IDYLL_ASSERT(position->y == 420);

            IDYLL_ASSERT(position->x == position2->x);
            IDYLL_ASSERT(position->y == position2->y);

            IDYLL_ASSERT(position3->x == 0);
            IDYLL_ASSERT(position3->y == 0);
        TEST_END

    TEST_SECTION_END

TEST_ENV_END